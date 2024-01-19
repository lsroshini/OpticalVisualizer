#include<stdio.h>
#include<string.h>
#include<math.h>
void question(int,int,char*);
void clear();
void sho(int,float,float,float,float,char,char,char);
int damp(float, float, float, float, float);
void sho_file(float,char,float);
void damp_file(float,char,float,float,float);
int main(){
    int x,y,z;
    char *s=(char*)malloc(300);
    char *a=(char*)malloc(300);
    printf("Hi! Let's begin with choosing the kind of equation.\n\n1.Simple harmonic oscillator\n2.Damped oscillation\n\nEnter your choice:");
    scanf("%d",&x);
    if(x==1){
        clear();
        printf("You have chosen Simple harmonic oscillator! Let's discuss some more details!\n\n");
        printf("1.Reference point is below equilibrium\n2.Reference point is above equilibrium\n3.Reference point is in equilibrium and moving upwards\n4.Reference point is in equilibrium and moving downwards");
        printf("\n\nEnter option: ");
        scanf("%d",&y);
    }else{
        clear();
        printf("You have chosen Damped oscillation!Let's discuss some more details!\n\n");
        printf("1.Reference point is below equilibrium\n2.Reference point is above equilibrium\n3.Reference point is in equilibrium and moving upwards\n4.Reference point is in equilibrium and moving downwards");
        printf("\n\nEnter option: ");
        scanf("%d",&y);
    }
    question(x,y,s);
    clear();
    float mass=0,equ=0,len=0,velo=0,cons=0,b=0;
    char m_unit,e_unit,len_unit;

        for(int i=0;i<strlen(s);i++){
            switch(s[i]){
                case '!':
                    printf("Enter the mass hung: ");
                    scanf("%f",&mass);
                    printf("Enter the unit of mass hung(g-gram;k-kilogram): ");
                    scanf("%*c%c",&m_unit);
                    (m_unit=='g')?mass/=1000:0;
                    break;
                case '#':
                    printf("Enter the length of equilibrium: ");
                    scanf("%f",&equ);
                    printf("Enter the unit(c-centimeter : m-meter): ");
                    scanf("%*c%c",&e_unit);
                    (e_unit=='c')?equ/=100:0;
                    break;
                case '%':
                    printf("Enter the length from the equilibrium :");
                    scanf("%f",&len);
                    printf("Enter the unit(c-centimeter : m-meter): ");
                    scanf("%*c%c",&len_unit);
                    (len_unit=='c')?len/=100:0;
                    break;
                case '@':
                    printf("Enter the velocity at which the mass is moving: ");
                    scanf("%f",&velo);
                    break;
                case '$':
                    printf("Enter the spring constant : ");
                    scanf("%f",&cons);
                    break;
                case '^':
                    printf("Enter the times of coefficient of instantaneous velocity: ");
                    scanf("%f",&b);
                    break;
                default:
                    break;
            }
        }
        if(x==1)
            sho(y,mass,equ,len,velo,m_unit,e_unit,len_unit);
        else
            damp(mass,cons,len,b,velo);
}

void sho(int y,float mass,float equ,float len,float v,char m_unit,char e_unit,char len_unit){
    float w;
    w=sqrt(((mass*9.8)/equ)/mass);
    switch(y){
    case 1:
        clear();
        printf("the differential equation solution is:\n");
        printf("%.3f cos(%.0ft)",len,w);
        sho_file(len,'c',w);
        break;
    case 2:
        len=equ-len;
        clear();
        printf("the differential equation solution is:\n");
        printf("-%.3f cos(%.0ft)",len,w);
        sho_file(-len,'c',w);
        break;
    case 3:
        clear();
        printf("the differential equation solution is:\n");
        printf("-%.3f sin(%.0ft)",v/w,w);
        sho_file(-v/w,'s',w);
        break;
    case 4:
        clear();
        printf("the differential equation solution is:\n");
        printf("%.3f sin(%.0ft)",v/w,w);
        sho_file(v/w,'s',w);
        break;
        }
    }

void clear(){
    system("cls");
}
void question(int x,int y,char *s){
    switch(x){
    case 1:
        switch(y){
        case 1:
            strcpy(s,"A ! mass struches a spring # find equation of motion of the mass if it is released from rest from the position % below the equilibrium position.");
            break;
        case 2:
            strcpy(s,"A ! mass struches a spring # find equation of motion of the mass if it is released from rest from the position % above the equilibrium position.");
            break;
        case 3:
            strcpy(s,"A ! mass struches a spring # find equation of motion of the mass if it is released from equilibrium position with an upward velocity of @m/s.");
            break;
        case 4:
            strcpy(s,"A ! mass struches a spring # find equation of motion of the mass if it is released from equilibrium position with an downward velocity of @m/s.");
            break;
        }break;
    case 2:
        switch(y){
        case 1:
            strcpy(s,"A ! mass is attached to a spring with spring constant $N/m the system is then immense in a medium imparting a damping force ^ times the instantaneous velocity of mass.Find the equation of motion.If it is released from rest at a point % below the equilibrium point.");
            break;
        case 2:
            strcpy(s,"A ! mass is attached to a spring with spring constant $N/m the system is then immense in a medium imparting a damping force ^ times the instantaneous velocity of mass.Find the equation of motion.If it is released from rest at a point % above the equilibrium point.");
            break;
        case 3:
            strcpy(s,"A ! mass is attached to a spring with spring constant $N/m the system is then immense in a medium imparting a damping force ^ times the instantaneous velocity of mass.Find the equation of motion.If it is released from equilibrium with an upward velocity of @m/s.");
            break;
        case 4:
            strcpy(s,"A ! mass is attached to a spring with spring constant $N/m the system is then immense in a medium imparting a damping force ^ times the instantaneous velocity of mass.Find the equation of motion.If it is released from equilibrium with an downward velocity of @m/s.");
            break;
        }break;
    }
}
int critically_damped(float b, float x, float velocity)
{
    float lambda, B;
    lambda = (-b) / 2;
    B = velocity - (x * lambda);
    damp_file(x,'k',lambda,0,B);
    printf("x(t) = %-.1fe^(%-.1ft) %-.1fte^(%-.1ft)/",x,lambda,B,lambda);
    return 0;
}
int overdamped(float discrement, float b, float x, float velocity)
{
    float lambda1,lambda2,A,B;
    lambda1=(sqrt(discrement) - b)/2;
    lambda2=((-b) - sqrt(discrement))/2;
    B=(x*lambda1 - velocity)/(lambda1 - lambda2);
    A=x - B;
    damp_file(A,'i',lambda1,lambda2,B);
    printf("x(t) = %-.1fe^(%-.1ft) %-.1fe^(%-.1ft)",A,lambda1,B,lambda2);
}
void under_damped(float discrement, float b, float x, float velocity)
{
    float r, i1, i2,B;
    r = -b/2;
    i1 = -discrement;
    i1 = sqrt(i1);
    i1 /= 2;
    i2 = -i1;
    B = (velocity - (x * r)) / i1;
    damp_file(x,'p',r,i1,B);
    printf("x(t) = %-.1fe^(%-.1ft)cos(%-.1ft) %-.1fe^(%-.1ft)sin(%-.1ft)",x,r,i1,B,r,i1);

}
int damp(float mass, float k, float x, float beta, float velocity)
{
    float w,b,c,d;
    w=sqrt(k/mass);
    b=beta/mass;
    c=k/mass;
    printf("The equation of damped oscillation is :\n");
    printf("f\"(x) + %.1ff'(x) + %.1f x = 0\n",b,c);
    d = pow(b, 2) - 4 * c;

    if (d < 0)
    {
        printf("The given spring mass system is of under-damped type\n");
        under_damped(d, b, x, velocity);
    }
    else if ((int)d == 0)
    {
        printf("The given spring mass system is of critically damped type\n");
        critically_damped(b, x, velocity);
    }
    else
    {
        printf("The given spring mass system is of over-damped type\n");
        overdamped(d, b, x, velocity);
    }
    return 0;
}
void sho_file(float x,char c,float y){
    FILE *f=fopen("t.txt","w");
    fprintf(f,"%f %c %f",x,c,y);
    fclose(f);
}
void damp_file(float a,char c,float e,float t,float b){
    FILE *f=fopen("t.txt","w");
    fprintf(f,"%f %c %f %f %f",a,c,e,t,b);
    fclose(f);
}

