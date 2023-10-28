#include "lib/hello.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include <iostream>
#include <memory>
#include <vector>

static std::unique_ptr<llvm::LLVMContext> the_context;
static std::unique_ptr<llvm::Module> the_module;
static std::unique_ptr<llvm::IRBuilder<>> builder;

int main() {
  std::cout << hello() << std::endl;

  // Initialize Module
  the_context = std::make_unique<llvm::LLVMContext>();
  the_module = std::make_unique<llvm::Module>("my cool jit", *the_context);

  builder = std::make_unique<llvm::IRBuilder<>>(*the_context);

  // main function
  auto main_function = llvm::Function::Create(
      llvm::FunctionType::get(
          llvm::Type::getDoubleTy(*the_context),
          std::vector<llvm::Type *>{llvm::Type::getDoubleTy(*the_context)},
          false),
      llvm::Function::ExternalLinkage, "main", the_module.get());

  main_function->arg_begin()->setName("first_arg");

  auto basic_block =
      llvm::BasicBlock::Create(*the_context, "entry", main_function);
  builder->SetInsertPoint(basic_block);

  auto val1 = llvm::ConstantFP::get(*the_context, llvm::APFloat(1.0));
  auto val3 = llvm::ConstantFP::get(*the_context, llvm::APFloat(3.0));

  auto lhs = builder->CreateFMul(val1, main_function->arg_begin(), "multmp");
  auto ret_val = builder->CreateFAdd(lhs, val3, "addtmp");
  builder->CreateRet(ret_val);

  llvm::verifyFunction(*main_function);

  the_module->print(llvm::errs(), nullptr);

  return 0;
}
