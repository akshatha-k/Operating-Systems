echo "Enter the coefficients of the quadratic eqn"
read a
read b
read c
d=`expr \( $b \* $b \) - 4 \* $a \* $c`
res=4
if [ $d -eq 0 ]
then
	res=0
elif [ $d -gt 0 ]
then
	res=1
else
	res=2
fi

case $res in
	"0") 
		r=`expr -1 \* $b \/ \( 2 \* $a \)`
		echo " Roots equal and value is $r"
		;;
	"1")
		sq=$(echo "sqrt($d)" | bc)
		r1=`expr \( -1 \* $b + $sq \) \/ \( 2 \* $a \)`
		r2=`expr \( -1 \* $b - $sq \) \/ \( 2 \* $a \)`
		echo " root 1: $r1"
		echo " root 2: $r2"
		;;
	"2")
		d=`expr -1 \* $d`
		sq=$(echo "sqrt($d)" | bc)
		part=`expr -1 \* $b \/ \( 2 \* $a \)`
		part2=`expr $sq \/ \( 2 \* $a \)`
		echo " roots are $part - $part2 i and $part + $part2 i"
		;;
	esac