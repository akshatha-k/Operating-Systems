a=$1
b=$3
case $2 in
	"+")
		res=$((a+b))
		;;
	"-")
		res=$((a-b))
		;;
	"X")
		res=$((a*b))
		;;
	"/")
		res=$((a/b))
		;;
	*)
		echo "illegal choice"
	esac
echo "$res"