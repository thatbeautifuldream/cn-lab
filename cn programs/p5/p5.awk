BEGIN{
tcppack=0
tcppack1=0
}
{
if($1=="s"&&$3=="_0_"&&$4="AGT"&&$8=="1540")
{
tcppack++;
}
if($1=="r"&&$3=="_2_"&&$4=="AGT"&&$8="1540")
{
tcppack1++
}
}
END{
printf("\n total no of data packets send fromn node0:%d\n",tcppack++)
printf("\n total no of data received at node2:%d\n",tcppack1++)
}
