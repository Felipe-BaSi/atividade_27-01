# Projeto de Matriz de LEDs com Raspberry Pi Pico

Este projeto utiliza um Raspberry Pi Pico para controlar uma matriz de LEDs e exibir números de 0 a 9. Além disso, um LED vermelho pisca continuamente enquanto os números são exibidos na matriz de LEDs.

## Requisitos

- Raspberry Pi Pico
- LEDs
- Botões
- Biblioteca `pico/stdlib`
- Biblioteca `hardware/pio`
- Biblioteca `hardware/clocks`

## Configuração de Hardware

- LEDs conectados aos pinos GPIO 11, 12 e 13 para as cores verde, azul e vermelho, respectivamente.
- Botões conectados aos pinos GPIO 5 e 6.
- Matriz de LEDs conectada ao pino GPIO 7.

## Funcionalidades

- Exibição de números de 0 a 9 na matriz de LEDs.
- LED vermelho piscando continuamente.
- Botão A (GPIO 5) para incrementar o número exibido.
- Botão B (GPIO 6) para decrementar o número exibido.

## Como Usar

1. Clone o repositório para o seu Raspberry Pi Pico.
2. Compile e carregue o código no Raspberry Pi Pico.
3. Conecte os LEDs e botões conforme a configuração de hardware.
4. Pressione o botão A para incrementar o número exibido na matriz de LEDs.
5. Pressione o botão B para decrementar o número exibido na matriz de LEDs.

## Vídeo do funcionamento

[![Vídeo de Apresentação](https://img.youtube.com/vi/BhpXofgJmk4/maxresdefault.jpg)](https://www.youtube.com/watch?v=BhpXofgJmk4)
