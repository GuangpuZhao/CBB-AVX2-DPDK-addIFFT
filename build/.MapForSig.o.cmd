cmd_MapForSig.o = gcc -Wp,-MD,./.MapForSig.o.d.tmp  -m64 -pthread  -march=native -DRTE_MACHINE_CPUFLAG_SSE -DRTE_MACHINE_CPUFLAG_SSE2 -DRTE_MACHINE_CPUFLAG_SSE3 -DRTE_MACHINE_CPUFLAG_SSSE3 -DRTE_MACHINE_CPUFLAG_SSE4_1 -DRTE_MACHINE_CPUFLAG_SSE4_2 -DRTE_MACHINE_CPUFLAG_AES -DRTE_MACHINE_CPUFLAG_PCLMULQDQ -DRTE_MACHINE_CPUFLAG_AVX -DRTE_MACHINE_CPUFLAG_RDRAND -DRTE_MACHINE_CPUFLAG_FSGSBASE -DRTE_MACHINE_CPUFLAG_F16C -DRTE_MACHINE_CPUFLAG_AVX2  -I/home/yujiamanong/Desktop/test/build/include -I/home/yujiamanong/Desktop/dpdk-stable-16.11.1/x86_64-native-linuxapp-gcc/include -include /home/yujiamanong/Desktop/dpdk-stable-16.11.1/x86_64-native-linuxapp-gcc/include/rte_config.h -O3 -I/home/yujiamanong/Desktop/test/BCCencode -I/home/yujiamanong/Desktop/test/intrinsics_interface -I/home/yujiamanong/Desktop/test/Process -I/home/yujiamanong/Desktop/test/process_data -I/home/yujiamanong/Desktop/test/process_data/process_datafunction -I/home/yujiamanong/Desktop/test/typeDef -I/home/yujiamanong/Desktop/test/VarINIT    -o MapForSig.o -c /home/yujiamanong/Desktop/test/Process/MapForSig.c 
