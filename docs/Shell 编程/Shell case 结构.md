## 「 Shell case 结构 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

### 💬 格式

```bash
case string in
exp1)
    若干个命令行
;;
exp2)
    若干个命令行
;;
...
*)  #用通配符*来处理无匹配项情况
esac
```

### 💬 举例

```bash
#!/bin/bash
echo "Enter A,B,C"
read letter
case $letter in
A|a)
    echo "you entered A."
;;
B|b)
    echo "you entered B."
;;
C|c)
    echo "you entered C."
;;
*)
    echo "not A,B,C."
esac
```

<div align="center">
    - End -
</div>