BEGIN{
tcppack=0
tcppack1=0
}
{
if($1=="r" && $4=="3" && $5=="tcp" && $6=="1540")
{
tcppack++;
}
if($1=="d" && $3=="2" && $5=="tcp" && $6=="1540")
{
tcppack1++;
}
}
END{
printf("\n total number of data packets received node3:%d\n",tcppack++);
printf("\n total number of data packets droped node2:%d\n",tcppack1++);
}
