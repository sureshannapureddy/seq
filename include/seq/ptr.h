#ifndef SEQ_PTR_H
#define SEQ_PTR_H

#include "types.h"

namespace seq {
	namespace types {

		class PtrType : public Type {
		private:
			Type *baseType;
			explicit PtrType(Type *baseType);
		public:
			PtrType(PtrType const&)=delete;
			void operator=(PtrType const&)=delete;

			llvm::Value *indexLoad(BaseFunc *base,
			                       llvm::Value *self,
			                       llvm::Value *idx,
			                       llvm::BasicBlock *block) override;

			void indexStore(BaseFunc *base,
			                llvm::Value *self,
			                llvm::Value *idx,
			                llvm::Value *val,
			                llvm::BasicBlock *block) override;

			Type *indexType() const override;

			Type *subscriptType() const override;

			llvm::Value *defaultValue(llvm::BasicBlock *block) override;

			llvm::Value *construct(BaseFunc *base,
			                       const std::vector<llvm::Value *>& args,
			                       llvm::BasicBlock *block) override;

			void initOps() override;

			bool isAtomic() const override;
			bool is(Type *type) const override;
			unsigned numBaseTypes() const override;
			Type *getBaseType(unsigned idx) const override;
			Type *getConstructType(const std::vector<Type *>& inTypes) override;
			llvm::Type *getLLVMType(llvm::LLVMContext& context) const override;
			seq_int_t size(llvm::Module *module) const override;
			static PtrType *get(Type *baseType) noexcept;
			static PtrType *get() noexcept;

			PtrType *clone(Generic *ref) override;
		};

	}
}

#endif /* SEQ_PTR_H */
