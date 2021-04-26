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

