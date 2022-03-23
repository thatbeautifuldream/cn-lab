BEGIN{
tcppack=0;
}
{
if($1=="r" && $4=="4" && $5=="cbr" && $6=="1000")
{
tcppack++;
}
}
END{
printf("\n total number of databpacket at node 4:%d\n",tcppack++);
}
