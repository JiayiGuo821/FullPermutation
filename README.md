# FullPermutation

## (基础任务)全排列生成算法实现：1. 字典序法 2. 递增进位制数法 3. 递减进位制数法 4. 邻位对换法

运行FullPermutation.cpp，进入命令行模式，流程如下：

+ 键入排列的位数
+ 键入全排列方法
+ 键入测试内容
+ 键入输入的内容
+ 输入一个排列，得到其对应的中介数和序号![1](https://github.com/JiayiGuo821/Markdown-Images/blob/master/FullPermutation/1.png?raw=true)
+ 或输入一个序号数，得到对应的中介数和排列![2](https://github.com/JiayiGuo821/Markdown-Images/blob/master/FullPermutation/2.png?raw=true)
+ 或输入一个中介数，得到对应的序号和排列![3](https://github.com/JiayiGuo821/Markdown-Images/blob/master/FullPermutation/3.png?raw=true)

此外也可以修改测试内容为2或3，测试全排列生成时间（键入2仅输出运算时间，键入3打印全排列并计算总运行时间）：

+ 上述流程测试内容修改为2时：![4](https://github.com/JiayiGuo821/Markdown-Images/blob/master/FullPermutation/4.png?raw=true)
+ 上述流程测试内容修改为3时：![5](https://github.com/JiayiGuo821/Markdown-Images/blob/master/FullPermutation/5.png?raw=true) 

## （新的想法）基于对称性的全排列生成算法 Symmetrical Permutation Generation (SPG)

无重排列的特点：序列总数一定为偶数（2k）。故对于任意一个排列，由于无重性，倒序输出该排列就可以得到另一个排列。

思路：得到k个互不为倒序的排列，则倒序输出就可以得到另外k个排列，至少可以减少一半的时间开销，实际上本方法在不考虑内存开销的情况下还可以减少更多时间开销。
![demo](https://github.com/JiayiGuo821/Markdown-Images/blob/master/FullPermutation/demo.png?raw=true)

实现简述：

对于长度为n的无重排列，按照首位数字（1-n）进行遍历，对于首位为t的情况，只要排列的末尾数字不小于t，则无论对于剩下的n-2位如何排列，生成的排列的逆序都一定不会在之前的遍历中出现过。而当首位为n时，无论剩余n-1位如何排列，逆序输出的结果都一定在前面的遍历中出现过。

因而，这种遍历方式，每次遍历的排列正序逆序输出就会对应全排列中的两个排列。于是问题化简为n(n-1)/2种情况下的n-2为全排列的生成。对于n-2个数字的全排列，基于基础任务中的任意算法实现即可（实际上该过程可以嵌套任意全排列生成算法）。可以看到时间复杂度减少了一半。

进一步可以看到，无论n-2位待排列的数字是什么，都一定可以排列成从小到大的n-2维的数组。而任意从小到大的n-2位数字的全排列与1,2,3...n-2的全排列在规则上并没有区别。因此我们只需实现一次1,2,3...n-2的全排列作为大小关系规则，每次按照该规则排列待排列的n-2个数字即可，时间复杂度可以得到进一步的缩减，但该缩减是以牺牲内存空间为代价的，在整个程序运行周期中，都需要存储一个长度为(n-2)!的规则数组。

测试结果如下：

+ 仅输出测试时间的对比结果![6](https://github.com/JiayiGuo821/Markdown-Images/blob/master/FullPermutation/6.png?raw=true)
+ 输出排列时总测试时间对比结果![7](https://github.com/JiayiGuo821/Markdown-Images/blob/master/FullPermutation/7.png?raw=true)

更进一步，考虑对于n-2位数字的全排列，又可以再次带入上述算法中基于在一些固定情况下的n-4的全排列来实现。基于此上述迭代，实际上问题可以继续化简为n-6,n-8...位数字的全排列，时间复杂度可以进一步减少，这部分的详细分析在大作业论文中给出。