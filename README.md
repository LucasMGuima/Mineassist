# Mineassist

Mineassist é um programa pensado no intuito de melhorar a experiencia ao se jogar Minecraft, como ajudar a organizar coordenadas e fazer calculos de distância e recursos.
Tudo em uma ferramente de terminal que não precisa de conexão com a internet.

> [!CAUTION]
> Mineassist ainda está em desenvolvimento, podendo apresentar alguns bugs ou não funcionar corretamenta.

## Desafios
### Compatibilidade
O entuito do programa é poder ser utilizado tanto em sistemas operacionais Windows como Linux, logo, é preciso diferenciar suas bibliotecas e partes de código especificas. Para isso foi utilizado a verificação atravez de marcadores como segue o exemplo:
```C
    #ifdef _WIN32 // Windows
    #include <Windows.h>
    #else // Linux
    #include <termios.h>
    #include <unistd.h>
    #endif
```
Onde durante a compilação do código é lincado a biblioteca ```Windows.h``` se o sistema operacional for Windos, e caso seja linux sera lincado a biblioteca ```termios.h``` e ```unistd.h```. Isso ocorre em outras áreas do código onde a implementação é diferente dependendo do sistema operacional.

### Interface
Para deixar a interface mais amigavel a usuarios comuns, a necissidade de apertar a tecla "Enter" foi removida, tento isso uma implementação difrente diferente nos dois sistemas operacionas alvos.  
Deste modo foi possivel atingir o menu inicial onde temos a ilusão de que o marcador se move entre as opções.