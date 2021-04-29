# QG训练营数据挖掘组第五周周记

2021年4月23日-4月29日

## 生活随记

### 4.23

大组训练营讲二叉树，最复杂的数据结构，确实不是吹的。

小组讲文献的检索与粗读，不是技术性的ppt，但是用处也很大！

另外，一睹程络师兄的芳颜，针不戳。

这次是最后一周训练营了，竟有完结撒花（感）之感（但我真的不想再来五周！再来五周我人必没）

平路师兄说的确实没错，只要能坚持下去，qg还是能进的。这不就少了一半的人吗。

### 4.24-4.25

二叉树真的好难/(ㄒoㄒ)/~~	我人要裂开了

主要是那个删除，情况太多了呀...

还有引用之前文件所引发的一些问题...晕😵

![image-20210425002551954](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210425002551954.png)

。。。

我把BinarySortTree T的声明语句放在main函数外（全局变量），再进行初始化，变量值就变正常了，太怪了...



只要我一引用这个库，就会因为写的类型不兼容而报错

![image-20210425154158860](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210425154158860.png)

但实际上两个数据类型是相同的。

![image-20210425154231815](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210425154231815.png)

![image-20210425154243683](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210425154243683.png)

所以**只能把stack和queue写在binary_sort_tree里了**，不然类型始终不兼容。

为啥不起同样的名字呢？

如果起了同样的名字，引用文件后就会**重复定义**

找了一个小时的bug，找到了...

![image-20210425165555571](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210425165555571.png)

bug：

现在能跑迭代前序遍历，但是会出现奇怪的数字

![image-20210425170611895](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210425170611895.png)

经我仔细的debug，发现是这里的问题

![image-20210425170644370](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210425170644370.png)

如果栈已空，回传的时候应该回传NULL，而不是NULL->data。所以要进行检查，如果s->top已为NULL，就传回NULL。

靠，还是错的。

经过细心的debug，我发现是这个地方出错了

![image-20210425172024294](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210425172024294.png)

node只是一个指向栈内结点data数据域的指针，但是我pop掉栈顶元素后，这个栈内结点就不复存在了，所以他也没有了data数据域，所以再对该区域进行操作的话，里面的数会是随机数。

解决方法：

先把他的node->right和node->left拿出来

最后采用了完全不同的逻辑解决了迭代的前序和中序遍历。

经过一天的不断尝试，始终没有做出来后序遍历和层序遍历。但是已经没有时间做了...

还要准备金工和线代的考试。再见。

### 4.26-4.28

上的离散完全听不懂啊！！！

我觉得我线代前面基础不太扎实，于是慢慢地过了一下矩阵的逆这一块知识，发现确实有很多东西不会。https://www.bilibili.com/video/BV1L7411a7Rz这个视频讲得不错，有详细的讲解。如果一开始上课就能找到这个合适的视频，现在应该不会显得那么仓促和拘束，搞得只能几天搞完线代，害。

专心复习线代。做笔记。

![image-20210429223544382](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210429223544382.png)

![image-20210429223610785](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210429223610785.png)

![image-20210429223633458](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210429223633458.png)

![image-20210429223643123](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210429223643123.png)

![image-20210429223651914](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210429223651914.png)

...

本身想跟广大的同学来我们学校图书馆拍视频给母校的高三学弟学妹加油的，结果星期三那天打完疫苗晕乎乎的，去不了广大载他过来呜呜呜。跟他约明天后天的，但是明天后天又有两门考试，烦。。。最后让我自己拍了...

**4.29**

今天要金工考试了，很慌...早上看了一下别人发的往年题目，发现很多题都很专业，要记的东西很多...瞬间没兴趣了，何况本身考试只占30%，应该不会挂吧，那就不复习了...

考完试了，感觉还行。

今天上完最后一节选修，也交完作业了。

**这学期的选修上完啦！完结撒花❀！**

今天训练营也算是正式结束了！感谢这五周的训练营，以作业的形式推动我去学习了许多东西，让我有所成长，有所收获。

有时间的话（二轮考核后），我会整理好这五周训练营数据结构的作业和中期考核的文件，发个博客，记录分析下这个学期。

**过去不可改变，未来握在手中。**

以充沛的状态准备进入二轮考核吧！不管进不进，做到不让自己后悔就行~

