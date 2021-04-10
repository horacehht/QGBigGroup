# QG训练营xx组第三周周记：
xxx年x月x日

## 生活随记



## 一周总结



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

## 下周规划



