/*BUSTOS CARREÓN RICARDO*/
#include <iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define Q_LIMIT 100 
#define BUSY      1  
#define IDLE      0  
#define MODLUS 2147483647
#define MULT1       24112
#define MULT2       26143

static long zrng[] =
{         1,
 1973272912, 281629770,  20006270,1280689831,2096730329,1933576050,
  913566091, 246780520,1363774876, 604901985,1511192140,1259851944,
  824064364, 150493284, 242708531,  75253171,1964472944,1202299975,
  233217322,1911216000, 726370533, 403498145, 993232223,1103205531,
  762430696,1922803170,1385516923,  76271663, 413682397, 726466604,
  336157058,1432650381,1120463904, 595778810, 877722890,1046574445,
   68911991,2088367019, 748545416, 622401386,2122378830, 640690903,
 1774806513,2132545692,2079249579,  78130110, 852776735,1187867272,
 1351423507,1645973084,1997049139, 922510944,2045512870, 898585771,
  243649545,1004818771, 773686062, 403188473, 372279877,1901633463,
  498067494,2087759558, 493157915, 597104727,1530940798,1814496276,
  536444882,1663153658, 855503735,  67784357,1432404475, 619691088,
  119025595, 880802310, 176192644,1116780070, 277854671,1366580350,
 1142483975,2026948561,1053920743, 786262391,1792203830,1494667770,
 1923011392,1433700034,1244184613,1147297105, 539712780,1545929719,
  190641742,1645390429, 264907697, 620389253,1502074852, 927711160,
  364849192,2049576050, 638580085, 547070247 };

float lcgrand(int stream);
void  lcgrandst(long zset, int stream);
long  lcgrandgt(int stream);
int next_event_type, num_custs_delayed, num_delays_required, num_events,
      num_in_q, server_status;
float area_num_in_q, area_server_status, mean_interarrival, mean_service,
      sim_time, time_arrival[Q_LIMIT+1], time_last_event, time_next_event[3],
      total_of_delays;
void  initialize(void);
void  timing(void);
void  arrive(void);
void  depart(void);
void  report(void);
void  update_time_avg_stats(void);
float expon(float mean);
int main()
{

    num_events = 2;
    printf("Ingrese el tiempo medio entre llegadas\n\n");
    scanf("%f", &mean_interarrival);
    printf("Ingrese el tiempo medio de servicio\n\n");
    scanf("%f", &mean_service);   
    printf("Ingrese el numero de clientes\n\n");
    scanf("%d", &num_delays_required);   
    printf("Sistema de fila de un solo servidor\n\n");
    printf("Tiempo medio entre llegadas%11.3f minutes\n\n", mean_interarrival);
    printf("Tiempo medio de servicio%16.3f minutes\n\n", mean_service);
    printf("Numero de clientes%14d\n\n", num_delays_required);
    initialize();
      while (num_custs_delayed < num_delays_required) {
      	 timing();
      	    update_time_avg_stats();
      	   switch (next_event_type) {
            case 1:
                arrive();
                break;
            case 2:
                depart();
                break;
            }
}
    report();
    return 0;
}
void initialize(void)
{
 sim_time = 0.0;
  server_status   = IDLE;
    num_in_q        = 0;
    time_last_event = 0.0;
    num_custs_delayed  = 0;
    total_of_delays    = 0.0;
    area_num_in_q      = 0.0;
    area_server_status = 0.0;
    time_next_event[1] = sim_time + expon(mean_interarrival);
    time_next_event[2] = 1.0e+30;
}
void timing(void)
{
    int   i;
    float min_time_next_event = 1.0e+29;

    next_event_type = 0;
     for (i = 1; i <= num_events; ++i)
        if (time_next_event[i] < min_time_next_event) {
            min_time_next_event = time_next_event[i];
            next_event_type     = i;
        }
        if (next_event_type == 0) {
        	 printf("\nLista de eventos vacios en el momento %f", sim_time);
        exit(1);
    }
  sim_time = min_time_next_event;
}
void arrive(void){
	 float delay;
	  time_next_event[1] = sim_time + expon(mean_interarrival);
	   if (server_status == BUSY) {
	   	  ++num_in_q;
	   	     if (num_in_q > Q_LIMIT) {
	   	     	printf("\nDesbordamiento del tiempo de llegada al momento\n\n");
                printf(" Tiempo %f", sim_time);
            exit(2);
        }
          time_arrival[num_in_q] = sim_time;
    }

    else {
    	 delay            = 0.0;
        total_of_delays += delay;
        
        ++num_custs_delayed;
        server_status = BUSY;
         time_next_event[2] = sim_time + expon(mean_service);
    }
}
void depart(void) {
	int   i;
    float delay;
     if (num_in_q == 0) {
     	 server_status      = IDLE;
        time_next_event[2] = 1.0e+30;
    }
     else {
     	   --num_in_q;
     	     delay            = sim_time - time_arrival[1];
        total_of_delays += delay;
         ++num_custs_delayed;
        time_next_event[2] = sim_time + expon(mean_service);
         for (i = 1; i <= num_in_q; ++i)
            time_arrival[i] = time_arrival[i + 1];
    }
    
}
void report(void){
	printf("\n\nRetraso promedio en la fila%11.3f minutos\n\n",
            total_of_delays / num_custs_delayed);
    printf("Numero medio en fila%10.3f\n\n",
            area_num_in_q / sim_time);
    printf("Utilizacion del servicio%15.3f\n\n",
            area_server_status / sim_time);
    printf("Finalizo la simulacion de tiempo%12.3f minutos", sim_time);
	
}
void update_time_avg_stats(void){
	float time_since_last_event;
	 time_since_last_event = sim_time - time_last_event;
    time_last_event       = sim_time;
      area_num_in_q      += num_in_q * time_since_last_event;
       area_server_status += server_status * time_since_last_event;

}
float expon(float mean){
	 return -mean * log(lcgrand(1));
}
float lcgrand(int stream)
{
    long zi, lowprd, hi31;

    zi     = zrng[stream];
    lowprd = (zi & 65535) * MULT1;
    hi31   = (zi >> 16) * MULT1 + (lowprd >> 16);
    zi     = ((lowprd & 65535) - MODLUS) +
             ((hi31 & 32767) << 16) + (hi31 >> 15);
    if (zi < 0) zi += MODLUS;
    lowprd = (zi & 65535) * MULT2;
    hi31   = (zi >> 16) * MULT2 + (lowprd >> 16);
    zi     = ((lowprd & 65535) - MODLUS) +
             ((hi31 & 32767) << 16) + (hi31 >> 15);
    if (zi < 0) zi += MODLUS;
    zrng[stream] = zi;
    return (zi >> 7 | 1) / 16777216.0;
}


void lcgrandst (long zset, int stream){
	zrng[stream] = zset;
}
long lcgrandgt (int stream)
{
    return zrng[stream];
}

