#define LED D3
hw_timer_t *timer = NULL;


void IRAM_ATTR onTimer() {
  digitalWrite(LED, !digitalRead(LED));
}

void setup(){
  pinMode(LED, OUTPUT);
  timer = timerBegin(0, 80, true);//TIMER 0 AKTIF ET VE 80 SCALA KULLAN
  timerAttachInterrupt(timer, &onTimer, true);//AKTIF ETTIGIMIZ TIMER'I KULLAN VE KESECEGI VODIDI GOSTER
  timerAlarmWrite(timer, 1000000, true);//TIMER'IN KESECEGI SURE 1 SANIYE
  timerAlarmEnable(timer);//AYARLANAN DUZENDE TIMER'I BASLAT
}