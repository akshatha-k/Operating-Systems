x=1
echo "enter a number"
read num
while [ $x -le $num ]
do
	echo $x
	x=`expr $x + 2`
done
