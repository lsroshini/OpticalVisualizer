import math
with open('t.txt','r') as f:
    d=[]
    data=f.readlines()
    for l in data:
        m=l.split(" ")
        d.append(m)
x=[]
y=[]
for i in d:
    if(len(i)==3):
        if(i[1]=='c'):
            for t in range(0,100,1):
                t/=10
                xx=float(i[0])*math.cos(float(i[2])*t)
                x.append(xx)
                y.append(t)
        else:
            for t in range(0,100,1):
                t/=10
                xx=float(i[0])*math.sin(float(i[2])*t)
                x.append(xx)
                y.append(t)
    else:
        if(i[1]=='i'):
            for t in range(0,100,1):
                t/=10
                xx=float(i[0])*(math.exp(float(i[2])*t)) + float(i[4])*(math.exp(float(i[3])*t))
                x.append(xx)
                y.append(t)
        elif(i[1]=='k'):
            for t in range(0,100,1):
                t/=10
                xx=float(i[0])*(math.exp(float(i[2])*t)) + float(i[4])*(math.exp(float(i[2])*t))
                x.append(xx)
                y.append(t)
        else:
            for t in range(0,100,1):
                t/=10
                xx=float(i[0])*(math.exp(float(i[2])*t))*(math.cos(float(i[3])*t)) + float(i[4])*(math.exp(float(i[2])*t))*(math.sin(float(i[2])*t))
                x.append(xx)
                y.append(t)
