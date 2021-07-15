//roubado do zanetti

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <locale.h>

//Vari�veis criadas quando houver necessidade


//vari�veis de imagens
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_BITMAP *capa = NULL;

//usado para resolver um bug
void * __gxx_personality_v0=0;
void * _Unwind_Resume =0;



void allegro()
{
//iniciando allegro, para receber input:
    if (!al_init())
    {
        printf("N�o foi poss�vel executar o allegro.\n");
    }
    if (!al_install_keyboard())
    {
        printf("N�o foi poss�vel executar o teclado.\n");
    }
    if (!al_install_mouse())
    {
        printf("N�o foi poss�vel executar o mouse.\n");
    }

}

void finalizar_allegro()
{
    al_destroy_display(display);
    al_uninstall_system();
    al_destroy_bitmap(capa);
}

/*void desenhar()
{

}
*/

int main(int argc, char **argv)
{
//acentua��o
    setlocale(LC_ALL,"");

//iniciando allegro
    allegro();

//criando uma janela
    display = al_create_display(800, 450);
    al_init_image_addon();



//criando foto de capa

    capa = al_load_bitmap("imagens/landscape.bmp");

    if (!capa)
    {
        printf("Erro em carregar imagens/landscape.bmp\n");
    }
    al_draw_bitmap(capa,0,0,0);
    al_flip_display(); //"Copies or updates the front and back buffers so that what has been drawn previously"
    al_rest(10.0);

    finalizar_allegro();


    return 0;
}

