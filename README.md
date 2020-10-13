

#               Informe




## Introducción

Al incio , nos resulto muy ajeno xv6 y no sabiamos muy bien como encarar el laboratorio.
Si bien sabiamos sobre syscalls , y un poco de manejo de memoria que estudiamos del teórico ,nos costo empezar a entender el codigo de xv6 ,fue un largo proceso ,pero fue solo hasta que entendimos como manejarnos entre los archivos buscando lo que necesitabamos saber de xv6 dentro del mismo y muy poco en fuentes externas.
Luego sobre vga ,leimos mucho la pagina de Santiago Romero ,el cual no solo tiene cursos de vga si no una gran variedad de cursos para programadores.
Fue un duro proceso hasta entender que vga no es complicado ,si no que lo complicado es entenderlo ,luego te das cuenta que es muy simple y manipulable.


___


## Desarrollo

El primer paso con el cual empezamos fue aprender sobre xv6 , utilizamos mucho el comando grep para ver como es que se implementaban las diferentes syscalls y demas curiosidades que nos podian generar, por ejemplo , que es la función P2V ,y como es que se implementaba dentro de xv6.
Antes de comenzar la Parte I , necesitabamos saber que era "Text mode" y "Graphics mode" , y como modificarlos.
Luego empezamos a intentar implementar la primera parte , escribir SO2020 en el pie de pagina.
Si bien la implementacion estaba dada ,teniamos que llamar en algún lado la función ,con la ayuda de un profe ,pudimos entender que hay ciertos archivos que son space kernel , como el console.c , en el cual podiamos usar la funcion sin problemas , porque justamente necesitabamos acceder a memoria y en el user space no está permitido.
Una vez realizado esto , extendimos la funcion implementada al principio (esto llevo tiempo ya que no sabiamos muy bien el como acceder a los registros , dando vueltas y vueltas al codigo de super ayuda entendimos mucho , sumado a lo leido en internet), para que se pueda cambiar de modo texto a grafico ,y viceversa , el problema que tuvimos es que no era manual , sino que al estar en console.c , solo podiamos hacer que se ejecute la funcion al inicio sin que el usuario pudiera interactuar.
Luego de esto , entendimos que era necesario implementar la syscall de la Parte III , la cual permite al usuario cambiar de modo texto(0) a grafico(1) , y viceversa ,las veces que quiera manualmente.
Hacer esto no fue simple porque si bien la implementacion de las syscall no era complicado ,al tener varios ejemplos de xv6 y como estas estaban implementados , era cuestion de imitarlo.
Pero el gran problema y en el cual se nos fue mucho tiempo , fue el entender como es que una funcion toma argumentos ,utilizando la funcion argint (en este caso argumentos enteros) , creo que una vez entendido esto ,hicimos una syscall que imprimia en pantalla "Hola" , al llamar a modeswitch 1 y "Chau" al llamar a modeswitch 0.
Al llegar a eso fue un alivio ,porque lo que restaba era solo copiar y pegar lo que ya habiamos hecho , dentro de donde implementamos la syscall (sysproc.c) ,una vez esto funcionaba bien , pasamos a la implementacion de plotpixel la cual fue muy sencilla , porque era casi copiar y pegar del enunciado. 
Ya teniendo esas dos syscalls implementadas ,nos dimos cuenta que todo implementado en sysproc.c quedaba horrible y muy poco legible , asique fue necesario modularizar. Pusimos todo dentro de un archivos vga.c y 
vga.h.
Pudimos hacer casi todos los extras que pedian , modularizar , plotrectangle , activar la paleta de 256 colores ,pero nos falto recuperar las fuentes , quedo pendiente ese apartado.
Y por ultimo la parte divertida fue dibujar algo en el modografico , quisimo hacer una funcion fuera de xv6 , para nosotros ,el cual toma una imagen y te devuelve un arreglo de enteros , para usar dicho arreglo en xv6 e imprimir algo mas bello de lo que nuestra imaginación podia hacer.Fue un total fracaso , creo que perdimos dia intentando implementar dicha funcion pero bueno , al final nos dividimos el trabajo y dibujar algo simple pero que tomo su tiempo.


___


## Conclusión

Un laboratorio divertido de hacer ,en el cual aprendimos sobre xv6 ,como manipularlos a nuestro gusto, como utilizar el userspace y kernel space.
Agregar syscalls nuevas , como es el que la syscall toma argumentos , como manejar el text mode y graphic mode ,como pintar y dibujar en pantalla.
Aprendimos a ultilizar los puertos para accerder a los registros de vga.
Si bien el estar en pandemia y el no poder estar en el aula y preguntar las dudas a los profes ,es un bajón , lo tomamos como una oportunidad de ser autodidactas y en el momento que vemos que en ninguna pagina , foro , libro logramos captar una idea , preguntarles a ellos por zulip.
Pero en fin , fue un muy lindo laboratorio y con un resultado divertido.


___



