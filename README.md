# Cronômetro para Robôs Seguidores

Projeto para ser utilizado como cronômetro automático baseado em um sensor de presença único para controlar o tempo de circuito para robôs seguidores de linha.

O sensor de presença precisa ser colocado no ponto de partida/chegada do circuito.

Após o início, o cronônometro é disparado. Somente após o percurso ser completado e passar pelo mesmo sensor o tempo será pausado. 

Ao final da tomada de tempo, pode-se utilizar do botão de reset para reinício do cronômetro.

## Componentes utilizados

* Sensor de presença LM393
* Arduíno Uno
* Display 16x2 com I2C
* Mini protoboard
* Resistor de 1K Ohm
* Push botton

## Desenho esquemático

![](https://github.com/michelpf/arduino-cronograph-line-follower/blob/main/schematics/schematics.png)

## Bibliotecas utilizadas

LiquidCyrstal I2C v.1.1.2

## Inspiração e referênicas

[GE Projetos e Tutoriais](https://www.youtube.com/watch?v=GihALLlaGIE&t=721s)

[Tronics Ik](https://www.youtube.com/watch?v=CvqHkXeXN3M)
