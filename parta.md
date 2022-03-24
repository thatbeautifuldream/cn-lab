Download [📑 PDF](./parta.pdf)

# Point to Point

```awk
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
```

# Point to Point (UDP)

```awk
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
```

# Ethernet LAN nodes(6-10)

```awk
BEGIN{
asize = 0;
starttime = 5.0;
stoptime = 0.1;
tput = 0;
}
{
event = $1;
time = $2;
size = $6;
if(event == "+")
{
if(time<starttime)
{
starttime = time;
}
}
if(event == "r")
{
if(time > stopttime)
{
stoptime = time;
}
asize += size;
}
tput = (asize/(stoptime-starttime))*(8/1000);
}
END{
printf("%f\t%f\n", time, tput);
}
```

# Ethernet LAN n-nodes

```awk
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
```

# Wireless LAN nodes

```awk
BEGIN{
tcppack=0
tcppack1=0
}
{
if($1=="s"&&$3=="_0_"&&$4="AGT"&&$8=="1598")
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
```

# Link State Routing

```awk
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
```
