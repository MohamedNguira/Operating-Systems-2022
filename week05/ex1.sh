gcc channel.c -o channel
gnome-terminal --title="Channel" -- ./channel
gcc subscriber.c -o subscriber
gcc publisher.c -o publisher
gnome-terminal --title="Publisher" -- ./publisher "$1"
for (( a=1; a<=$1; a++ ))
do
   gnome-terminal --title="Subscriber $a" -- ./subscriber
done

