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

    Wave_Header header;

    FILE *arquivo = fopen("sound.wav", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    /* Ler o cabeçalho */
    fread(&header, sizeof(header), 1, arquivo);

    /* Imprime o cabeçalho */
    printf("chunk_id: %s\n", header.chunk_id);
    printf("Formato: %s\n", header.format);
    printf("Tamanho da 'struct' header: %ld bytes\n", sizeof(header));
    printf("Taxa de amostragem: %u Hz\n", header.sample_rate);
    printf("Número de canais: %d %s\n",
        header.num_channels,
        (header.num_channels == 1) ? "(mono)":"(stereo)"
    );

    /* Fechar o arquivo */
    fclose(arquivo);

    return 0;
}
