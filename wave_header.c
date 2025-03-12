#include <stdio.h>
#include <stdint.h>

/* Define um tipo de Estrutura para o cabeçalho WAV (simplificado) */
typedef struct {
    char        chunk_id[4];
    uint32_t    chunk_size;
    char        format[4];
    char        subchunk1_id[4];
    uint32_t    subchunk1_size;
    uint16_t    audio_format;
    uint16_t    num_channels;
    uint32_t    sample_rate;
    uint32_t    byte_rate;
    uint16_t    block_align;
    uint16_t    bits_per_sample;
    char        subchunk2_id[4];
    uint32_t    subchunk2_size;
} Wave_Header;

int main() {

    FILE *arquivo = fopen("sound.wav", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    Wave_Header header;

    /* Ler o cabeçalho */
    fread(&header, sizeof(header), 1, arquivo);

    /* Imprimir a taxa de amostragem */
    printf("Taxa de amostragem: %u Hz\n", header.sample_rate);

    /* Imprimir o número de canais */
    printf("Número de canais: %d %s\n",
        header.num_channels,
        (header.num_channels == 1) ? "(mono)":"(stereo)"
    );

    /* Fechar o arquivo */
    fclose(arquivo);

    return 0;
}
