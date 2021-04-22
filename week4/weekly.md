# QG训练营数据挖掘组第四周周记

2021年4月16日-4月22日

## 生活随记

### 4.16

容量满满。大组排序当头一棒。小组继元师兄很广度地介绍了爬虫

1.aiohttp支持异步

2.XPath语法，lxml

3.python伪造user-agent库

4.IP代理

5.redis

6.动态页面	ajax反爬虫

7.async	await，异步地关键词

8.SQL是一种语言，MySQL是一个数据库，Navicat是可视化管理

### 4.17

无言。

### 4.18

答辩非常尬，开始写排序的大组作业。

昨天写了个隐藏很深的bug，发了篇博客进行记录。https://blog.csdn.net/m0_50123831/article/details/115843169

### 4.19

放滚键盘这次我觉得我做的挺好的。（曾让路哥胆寒的颜文字）

![image-20210419220822382](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210419220822382.png)

而且这次我还用了函数指针数组来进行不同排序函数的调用，感觉收获很大。

颜色排序的代码

![image-20210419221244709](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210419221244709.png)

在一个无序序列中找到第K大/小的数的代码

![image-20210419221342081](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210419221342081.png)

一些测试出来的bug。

![image-20210419220722857](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210419220722857.png)

今天下午还收到jb回复我的邮件，说我通过了教育认证，可以白嫖了。

先白嫖个pycharm专业版，再嫖个CLion，再嫖个IDEA

### 4.20

本次爬虫打算用XPath，

我发现每一页的电影url都存放在一个名为ol的节点下

url存在于ol节点的a的href属性



评价人数

![image-20210420142922377](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210420142922377.png)

剧情简介

![image-20210420143253476](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210420143253476.png)

发现上映日期和电影时长获取的函数编写错误，需要重新编写

观察了很多网页，上映日期节点都是以下样式↓

![image-20210420182606107](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210420182606107.png)

```python
date = html.xpath('//span[@property = "v:initialReleaseDate"]/text()')
```

经过观察，上映日期可能会有多种，所以要处理一下

**约束条件一定要强且准确，这样才不会爬到杂项**

经过观察，那其中一个网页作例子https://movie.douban.com/top250?start=25&filter=

网页前缀为https://movie.douban.com/top250?

后跟着start与filter参数

filter不变，start从0开始每次递增25

### 4.21

**明天家里有事，所以下午回家**。

在家里

学习pymysql的用法，不能通过

```
cursor.execute(sql, data)
```

把数字录进数据库，因为这个语句在处理data时会将其中的所有数据改为str，导致我写的%d一直报错`data must be a number, not str`，这个函数的用法真是颇费了我一周折，最后索性**把所有数据类型全部改成char**录进去，以绝后患。

...设置2-4秒的随机数等待时间被封ip了，呜呜呜。

睡觉。

### 4.22

完工了。撒花！

![image-20210422123020779](https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210422123020779.png)

## 一周总结

这周过得挺紧凑的。周五，六准备ppt，文档，周日答辩，答辩完写排序的测试系统，周一完工。

周二开始爬虫，用XPath筛选信息（之前都是用re的findall），发现XPath异常地好用。

周三开始学习数据库并尝试将一个电影的信息存入，一个电影信息存入成功后开始进行爬取存储。

因为封ip还有回家的原因，爬虫周四上午才做完。

## 存在问题

1. 编写的颜色排序和找到第k大的数不知道放在系统的哪个地方，就没写到系统里了
2. **数据库操作语句不熟**，可以在之后多加练习

## 下周规划

1. 了解各种评估方法（混淆矩阵等...）
2. 照着sklearn给出的算法，逐一去了解原理并尝试使用

