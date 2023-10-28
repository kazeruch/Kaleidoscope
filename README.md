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
$ llvm-config-16 --version
16.0.6
```