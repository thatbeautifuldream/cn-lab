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
