BEGIN{
tcppack=0;
}
{
if ($1=="r"&&$4=="5"&&$5=="tcp"&&$6=="1540")
{
tcppack++;
}
}
END{
printf("\n total number of data packets at node5:%d\n",tcppack++);
}
