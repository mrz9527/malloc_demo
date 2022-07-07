用于测试malloc底层，小内存申请和大内存申请时，
内核层调用的函数不同：brk和mmap
在虚拟内存地址空间中，小内存分配在堆区，大内存分配在映射区
brk申请的内存，释放的时候没有立即返还给操作系统，相当于内存池模型，主要是为了可以反复利用。
mmap申请的大内存，立即返回给了操作系统

brk申请的内存，虽然释放了，但是没有立即返回给操作系统，多次申请不同规格的小内存，会造成这些小内存被泄露，应用程序占用的内存变大）而valgrind工具又检测不到这些内存泄露。