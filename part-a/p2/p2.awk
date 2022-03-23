BEGIN{
tcppack=0
tcppack1=0
}
{
if($1=="r" && $4=="2" && $5=="tcp" && $6=="1540")
{
tcppack++;
}
if($1=="r" && $4=="2" && $5=="cbr" && $6=="1000")
{
tcppack1++;
}
}
END{
printf("\n total number of tcp data packets sent between node0 and node2:%d\n",tcppack++);
printf("\n total number of udp data packets out between node1 and node2:%d\n",tcppack1++);
}
