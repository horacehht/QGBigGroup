[TOC]

## QG训练营数据挖掘组第一周周记：

### 生活随记

🐱迎来了春天的季节，晚上总是叫，不得安宁

#### 3.27-3.28

肝链表，那个单链表奇偶反转想了很久也没想出来Orz。

用了很多时间。

单链表只防了外面滚键盘，没防里面滚键盘...

#### 3.29

上了离散高数思修体育。

- 离散...不说了，这个科目难以言表。

- 高数上了多元函数的隐函数求导...感觉稍微有点难理解。我们和蔼可亲的许老师介绍了三种方法求偏导数，并强烈推荐全微分方法。

- 思修。上的是理想信念一课。有个灵魂拷问：你的理想是什么？你有对未来作出清晰的规划吗？

想了想，我的理想是就是成为一个正直，善良，对社会有用的人，我想做一份跟**生物或医学**有关的工作，利用大数据的技术去攻克一些难题。为什么呢？因为这类职业能给我带来满足感，对社会有较大的贡献。

但比较惭愧的是，一直都没有清晰的规划，有目标也是比较模糊的，没有落实到周月每周每天要完成什么...可能这就是我跟别人的差距吧。

- 体育，跆拳道练横踢，踢起来感觉怪怪的...没有直踢的那种feel

#### 3.30

代码实现了梯度下降法的多元线性回归，得找个数据集测试一下

我自己在kaggle上找了份预测房价的数据集，处理了一下，从4k6条数据减少到1k多...

但测试出来效果不佳...（甚至有warning: timeout error，算法写的不太好吧...）

#### 3.31

不知道干了啥...？

#### 4.1

看大话数据结构，实现部分栈的函数

### 一周总结

#### 函数指针

了解了回调函数，对指针的认识更深了。

#### git的下载安装与学习

[教程](https://www.liaoxuefeng.com/wiki/896043488029600)看的是廖雪峰的

`git config --global user.name "horace"`	用户名配置为双引号内的名字horace

`git  config --global user.email "horace_01@126.com"`	邮箱配置为双引号内的邮箱

`mkdir learngit`	创建一个叫learngit的空目录，mkdir实际上是make directory

`cd learngit`	首先进入桌面，再进到learngit目录下

由下图可见

![image-20210327093706892](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210327093706892.png)

（刚刚上传上面这张图片的时候上传失败了，跑去阿里云检查一下发现没问题，再上传一次，好了，原来是网络波动的问题）

`pwd`	**显示当前目录**

`git init`	**进行初始化**，把这个目录变成Git可以管理的仓库

`git add 文件名`		**将文件添加到仓库**，文件名要带格式后缀（后文文件名均指此格式）

`git commit -m "explanation"`	**把文件提交到仓库**，-m ""的内容是本次提交的说明

对readme.txt进行改动后

`git status`	**可以看当前仓库的状态**

`git diff`	**可看修改的内容**，将修改前的内容以-红色标记，修改后的内容以+绿色标记。这个跟markdown代码块里的diff语言有异曲同工之妙。

`git diff HEAD --readme.txt`

```diff
-Git is a version control system
+Git is a distributed version control system
```

`git log`	**查看提交(commit)日志**

`git reset --hard HEAD^`	**回退到上一个版本**，^表示上一个版本，HEAD表示当前版本，如果要回溯到上100个版本，就写成`HEAD~100`

此处reset后，git log也看不到之前那个版本的日志了，但是如果知道之前那个commit id的话，还是可以把他恢复的，通过`git reset --hard 那个commit id`命令恢复版本（版本号没必要写全，前几位就可以了，Git会自动去找。当然也不能只写前一两位，因为Git可能会找到多个版本号，就无法确定是哪一个了）

`cat 文件名`	显示文件内的内容

`git reflog`	**查看命令日志**



##### 工作区与暂存区

add都是将文件提交至暂存区

commit是把暂存区的文件都压到工作区

而git status记录的是暂存区的情况



`rm 文件名`	工作区中删除掉文件

此时`git status`会提示你工作区与版本库不同

此时你有两种选择

1. 删掉版本库中的文件`git rm 文件名`，然后再`git commit -m"..."`提交说明此次的操作
2. 如果工作区误删，但版本库里还有此文件的话，可以用`git checkout -- 文件名`把工作区的文件恢复。（**实质上是版本库里的东西替换掉工作区的东西**）

#### 连接远程库github

##### 创建密钥对

在git bash中敲入命令

`$ ssh-keygen -t rsa -C "horace_01@126.com"`

创建了`id_rsa`和`id_rsa.pub`两个文件，是SSH的密钥对,生成后，进github的settings设置SSH keys。

于是我的关联远程库命令是：`git remote add origin git@github.com:horacehht/仓库名.git `

推送命令`git push -u origin master`

把本地库的内容推送到远程，用`git push`命令，实际上是把当前分支`master`推送到远程。由于远程库是空的，我们第一次推送`master`分支时，加上了`-u`参数，Git不但会把本地的`master`分支内容推送的远程新的`master`分支，还会把本地的`master`分支和远程的`master`分支关联起来，在以后的推送或者拉取时就可以简化命令。

之后就可以`git push origin master`

`git remote -v`查看远程库信息

`git remote rm origin`解除origin与远程库的关联

` $ git remote add origin https://github.com/daoke0818/testGit2.git`这样的关联也是可以的

#### git的一些小操作

进入某个盘的特定文件夹

```
cd f:
↑进入特定盘
cd 文件夹名/子目录/...
```



#### 推荐应用

##### DeepL

下载了一个DeepL翻译软件，把原来的有道删了，我发现这翻译是真的给力。

##### Overleaf

overleaf注册接口有bug需要翻墙

### 存在问题

#### 链表奇偶对换

1-2-3-4，12对换后正常，3-4对换后，1却指着3而不是4，好烦，想了很久

![image-20210327230227179](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210327230227179.png)

觉得先拆成两个链表会比较靠谱

1-2-3-4-5

①1-3-5

②2-4

然后从2中逐个抽取加到1中

#### 程序崩溃

倬熙师兄：“怎么随便一操作就崩了呀”

呜呜呜，对程序考虑不够细致

只防了外面滚键盘...

输入负数个结点居然也行（我还真没想到用户输负数...）

删除整表后遍历啥的也会崩溃

哎...学艺不精

### 下周规划

 周一周二算法（下周看logistic），周三爬虫，周四看数据结构，周末开搞qg作业