x=1
res=1
echo "Enter number"
read num
while [ $x -le $num ]
do
res=`expr $x \* $res`
x=`expr $x + 1`
done
echo "Factorial : $res "