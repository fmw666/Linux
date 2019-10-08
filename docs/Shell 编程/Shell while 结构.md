## 「 Shell while 结构 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

### 💬 格式

```bash
while 条件测试
do
    若干个命令行
done
```

### 💬 举例

```bash
#!/bin/bash
x=0
while (($x<=10))
do
    echo $x
    x=$(($x+1))
done
```

<div align="center">
    - End -
</div>