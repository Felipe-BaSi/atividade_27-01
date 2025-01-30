#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "atividade_27_01.pio.h"
#include <stdlib.h>

#define NUM_PIXELS 25
#define OUT_PIN 7

const uint led_g = 11;
const uint led_b = 12;
const uint led_r = 13;

const uint but_A = 5;
const uint but_B = 6;

PIO pio = pio0;
double r[NUM_PIXELS] = {0}, g[NUM_PIXELS] = {0}, b[NUM_PIXELS] = {0};
uint sm;
int cont = -1;

volatile uint32_t last_time = 0;

uint32_t matrix_rgb(double b, double r, double g) {
    unsigned char R, G, B;
    R = r * 255;
    G = g * 255;
    B = b * 255;
    return (G << 24) | (R << 16) | (B << 8);
}


void update_led_matrix(double *r, double *g, double *b, PIO pio, uint sm) {
    uint32_t valor_led;
    for (int16_t i = 0; i < NUM_PIXELS; i++) {
        valor_led = matrix_rgb(b[i], r[i], g[i]);
        pio_sm_put_blocking(pio, sm, valor_led);
    }
}

void display_numbers(double *r, double *g, double *b, PIO pio, uint sm){

    int i;

    double num_0[NUM_PIXELS] = {0.0, 0.1, 0.1, 0.1, 0.0,
                                0.0, 0.1, 0.0, 0.1, 0.0, 
                                0.0, 0.1, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.1, 0.1, 0.0};

    double num_1[NUM_PIXELS] = {0.0, 0.0, 0.1, 0.0, 0.0,
                                0.0, 0.0, 0.1, 0.0, 0.0, 
                                0.0, 0.0, 0.1, 0.0, 0.0,
                                0.0, 0.0, 0.1, 0.0, 0.0,
                                0.0, 0.0, 0.1, 0.0, 0.0};

    double num_2[NUM_PIXELS] = {0.0, 0.1, 0.1, 0.1, 0.0,
                                0.0, 0.1, 0.0, 0.0, 0.0, 
                                0.0, 0.1, 0.1, 0.1, 0.0,
                                0.0, 0.0, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.1, 0.1, 0.0};

    double num_3[NUM_PIXELS] = {0.0, 0.1, 0.1, 0.1, 0.0,
                                0.0, 0.0, 0.0, 0.1, 0.0, 
                                0.0, 0.1, 0.1, 0.0, 0.0,
                                0.0, 0.0, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.1, 0.1, 0.0};

    double num_4[NUM_PIXELS] = {0.0, 0.1, 0.0, 0.0, 0.0,
                                0.0, 0.0, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.1, 0.1, 0.0,
                                0.0, 0.1, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.0, 0.1, 0.0};

    double num_5[NUM_PIXELS] = {0.0, 0.1, 0.1, 0.1, 0.0,
                                0.0, 0.0, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.1, 0.1, 0.0,
                                0.0, 0.1, 0.0, 0.0, 0.0,
                                0.0, 0.1, 0.1, 0.1, 0.0};

    double num_6[NUM_PIXELS] = {0.0, 0.1, 0.1, 0.1, 0.0,
                                0.0, 0.1, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.1, 0.1, 0.0,
                                0.0, 0.1, 0.0, 0.0, 0.0,
                                0.0, 0.1, 0.1, 0.1, 0.0};

    double num_7[NUM_PIXELS] = {0.0, 0.1, 0.0, 0.0, 0.0,
                                0.0, 0.0, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.1, 0.1, 0.0};

    double num_8[NUM_PIXELS] = {0.0, 0.1, 0.1, 0.1, 0.0,
                                0.0, 0.1, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.1, 0.1, 0.0,
                                0.0, 0.1, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.1, 0.1, 0.0};

    double num_9[NUM_PIXELS] = {0.0, 0.1, 0.1, 0.1, 0.0,
                                0.0, 0.0, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.1, 0.1, 0.0,
                                0.0, 0.1, 0.0, 0.1, 0.0,
                                0.0, 0.1, 0.1, 0.1, 0.0};
                            

    switch(cont){

        case 0:

            for(i = 0; i < NUM_PIXELS; i++){
            r[i] = 0.0;
            g[i] = num_0[i];
            b[i] = 0.0;
            }
            
        break;

        case 1:

            for(i = 0; i < NUM_PIXELS; i++){
            r[i] = 0.0;
            g[i] = num_1[i];
            b[i] = 0.0;
            }
            
        break;

        case 2: 

            for(i = 0; i < NUM_PIXELS; i++){
            r[i] = 0.0;
            g[i] = num_2[i];
            b[i] = 0.0;
            }

        break;

        case 3: 

            for(i = 0; i < NUM_PIXELS; i++){
            r[i] = 0.0;
            g[i] = num_3[i];
            b[i] = 0.0;
            }

        break;

        case 4: 

            for(i = 0; i < NUM_PIXELS; i++){
            r[i] = 0.0;
            g[i] = num_4[i];
            b[i] = 0.0;
            }

        break;

        case 5: 

            for(i = 0; i < NUM_PIXELS; i++){
            r[i] = 0.0;
            g[i] = num_5[i];
            b[i] = 0.0;
            }

        break;

        case 6: 

            for(i = 0; i < NUM_PIXELS; i++){
            r[i] = 0.0;
            g[i] = num_6[i];
            b[i] = 0.0;
            }

        break;

        case 7: 

            for(i = 0; i < NUM_PIXELS; i++){
            r[i] = 0.0;
            g[i] = num_7[i];
            b[i] = 0.0;
            }

        break;

        case 8: 

            for(i = 0; i < NUM_PIXELS; i++){
            r[i] = 0.0;
            g[i] = num_8[i];
            b[i] = 0.0;
            }

        break;

        case 9: 

            for(i = 0; i < NUM_PIXELS; i++){
            r[i] = 0.0;
            g[i] = num_9[i];
            b[i] = 0.0;
            }


        break;

        default:

            for(i = 0; i < NUM_PIXELS; i++){
            r[i] = 0.0;
            g[i] = 0.0;
            b[i] = 0.0;
            }

        break;
    }
    update_led_matrix(r, g, b, pio, sm);
}

static void gpio_irq_handler(uint gpio, uint32_t events);

int main() {
    bool ok;

    sm = pio_claim_unused_sm(pio, true);

    gpio_init(led_r);
    gpio_set_dir(led_r, GPIO_OUT);
    gpio_init(led_g);
    gpio_set_dir(led_g, GPIO_OUT);
    gpio_init(led_b);
    gpio_set_dir(led_b, GPIO_OUT);

    gpio_init(but_A);
    gpio_set_dir(but_A, GPIO_IN);
    gpio_pull_up(but_A);
    gpio_init(but_B);
    gpio_set_dir(but_B, GPIO_IN);
    gpio_pull_up(but_B);

    ok = set_sys_clock_khz(128000, false);

    stdio_init_all();

    gpio_set_irq_enabled_with_callback(but_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(but_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    uint offset = pio_add_program(pio, &atividade_27_01_program);
    atividade_27_01_program_init(pio, sm, offset, OUT_PIN);


    while(1){

        gpio_put(led_r, true);
        sleep_ms(100);
        gpio_put(led_r, false);
        sleep_ms(100);

    }

}

void gpio_irq_handler(uint gpio, uint32_t events){
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    if(current_time - last_time > 200000){

        if(gpio == but_A && cont < 9){

            cont++;

        } else if (gpio == but_B && cont > 0){

            cont--;

        }

        last_time = current_time;

        display_numbers(r, g, b, pio, sm);
    }
}
