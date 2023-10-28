# Kaleidoscope with LLVM 16

## LLVMのinstall

### Ubuntu
https://apt.llvm.org/ を見てinstallする。
```bash
$ wget https://apt.llvm.org/llvm.sh
$ chmod +x llvm.sh
$ sudo ./llvm.sh 16
$ apt list | grep llvm-16
llvm-16/unknown,now 1:16.0.6~++20230710042046+7cbf1a259152-1~exp1~20230710162136.105 amd64 [installed,automatic]
$ sudo apt-get install llvm-16
$ llvm-config-16 --version
16.0.6
```

## トラブルシューティング
参考: https://github.com/llvm/llvm-project/issues/53950
### -- Could NOT find FFI (missing: HAVE_FFI_CALL)
```bash
sudo apt-get update
sudo apt-get install libffi-dev
```
### 