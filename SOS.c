#include "pico/stdlib.h"


#define LED_PIN 13
#define BUZZER_PIN 21
#define PONTO 200
#define TRACO 800
#define TEMPO_GAP 125
#define INTERVALO 250
#define CICLO 3000

void blinkLED(int duration){
    gpio_put(LED_PIN, 1);
    sleep_ms(duration);
    gpio_put(LED_PIN,0);
    sleep_ms(INTERVALO);
}

void beepBuzzer(int duration){
    gpio_put(BUZZER_PIN, 1);
    sleep_ms(duration);
    gpio_put(BUZZER_PIN, 0);
    sleep_ms(INTERVALO);
}

void enviaSOS(){

    for(int i = 0;i < 3; i++){
        blinkLED(PONTO);
        beepBuzzer(PONTO);
    }

    sleep_ms(INTERVALO);

    for(int i = 0; i < 3; i++){
        blinkLED(TRACO);
        beepBuzzer(TRACO);
    }
    
    sleep_ms(INTERVALO);

    for(int i = 0; i < 3; i++){
        blinkLED(PONTO);
        beepBuzzer(PONTO);
    }

    sleep_ms(CICLO);
}

int main(){
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_set_dir(LED_PIN,GPIO_OUT);

    while(true){
        enviaSOS();

    }
    return 0;
}

