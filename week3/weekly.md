# QG训练营数据挖掘组第三周周记：
2021年4月9日-4月15日

## 生活随记

**4月9日**

中期考核要开始了，关一周朋友圈，以免分心

**4月10日**

完成大组作业的泛型顺序队和链队，存储输出想了很久。

**4月10-11日**

由于周一高数和离散都会小测，所以分析数据集之余抽出很多时间来复习。比较怕高数考的差。

交一份全是1的样本，练练怎么提交。

**4月12日**

好！考完高数和离散了。高数凉一点，离散彻底凉。

考完试我又是一条好汉，全力中期考核！

为了用自己写的算法，出了很多奇怪的Bug

**4月13-15日**

中期考核...触碰无数bug...调了无数参...A榜没破71，B榜破了71。

顺便过了下原神的新剧情（？！）《我们终将相逢》，坑越挖越大了，不过我喜欢。

## 一周总结

通过编写泛型队列，了解并运用了memcpy函数用于字节拷贝，解决了泛型队列的存储和输出问题。

通过中期考核的数据分析，对pandas，numpy的熟悉程度大大增加了！（此处应有b站熊猫头表情）

特别是pandas的loc，iloc，concat，numpy的astype，reshape

## 存在问题

### 1.LQueue

<img src="https://horacehhtbucket.oss-cn-guangzhou.aliyuncs.com/img/image-20210410122121903.png" alt="image-20210410122121903" style="zoom: 80%;" />

当为空队时，Q->rear和Q->front都指向头结点，会造成对已free过的空间再free一次，程序崩溃。

代码修改如下

```c
修改前：
while(p!=Q->rear){
    q = p->next;
    free(p);
    p = q;
}
free(Q->rear);
free(Q->front);

修改后：
while (p!=NULL){
    q = p->next;
    free(p);            
    p = q;
}
```

解决问题。

### 2.matplotlib绘图问题

不管运行什么代码，只要是用matplotlib画图的，都会报这个错`RuntimeError: In FT2Font: Can not load face`

报错的原因是中文字体的设置

解决方法：

1. 删除字体缓存.matplotlib/文件夹下的所有文件及文件夹
2. 并通过matplotlib.rcParams设置字体

```python
import matplotlib
matplotlib.rcParams['font.family'] = 'sans-serif'  
matplotlib.rcParams['font.sans-serif'] = 'NSimSun,Times New Roman'# 中文设置成宋体，除此之外的字体设置成New Roman 
```

## 下周规划

1.中期考核完进行进行算法的学习，学bp。

2.搭建个人博客。（中期目标）

3.熟悉matplotlib等绘图库进行图表的绘制