/*
** ETNA PROJECT, 08/05/2019 by delapo_a
** octocat
** File description:
**      read audio file to octocat
*/

#include "./octocat.h"

static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play
static Uint32 audio_len_base;
static Uint8 *wav_buffer; // buffer containing our audio file

int play_sound_SDL()
{

    static Uint32 wav_length; // length of our sample
    static SDL_AudioSpec wav_spec; // the specs of our piece of music
    

    if (SDL_Init(SDL_INIT_AUDIO) < 0)
            return 1;
    if( SDL_LoadWAV(MUS_PATH, &wav_spec, &wav_buffer, &wav_length) == NULL )
      return 1;
    wav_spec.callback = my_audio_callback;
    wav_spec.userdata = NULL;
    audio_pos = wav_buffer; // copy sound buffer
    audio_len = wav_length; // copy file length
    if ( SDL_OpenAudio(&wav_spec, NULL) < 0 ){
      exit(-1);
    }
    audio_len_base = audio_len;
    SDL_PauseAudio(0);
    return 0;
}
void my_audio_callback(void *userdata, Uint8 *stream, int len) {
    (void) userdata;
    if (audio_len == 0) {
        audio_len = audio_len_base;
        audio_pos -= audio_len_base;
    }
    len = ( len > (int)audio_len ? (int)audio_len : len );
    SDL_memcpy (stream, audio_pos, len);                  // simply copy from one buffer into the other
    SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another
    
    audio_pos += len;
    audio_len -= len;
}