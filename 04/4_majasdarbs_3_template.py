#!/usr/bin/env python3
'''
Python mājasdarbs Nr.4-3

Uzdevums: aizpildīt vietas ar atzīmi TODO
Apraksts: Šīs programmas uzdevums ir lejupielādēt grāmatu 
          un veik dažādas darbības ar tās saturu
'''
import urllib.request
import os
import string
import sys
import helperMajasdarbs

#####################
## Funkcijas
#####################

def url_to_filename( url ):
    """
        Funkcija paņem kādu URL sadala to ar atdalītāju / un izvedo faila nosaukumu
        Ievade: URL
        Izvade: Faila nosaukums

    """
    *tmp, part1, part2 = url.split( "/" )    
    print( tmp, part1, part2 )
    if len(part1) > 0:
        filename = part1 + "_" + part2
    else:
        filename = part2
    return filename

def get_text( url ):
    """
        Funkcija izveido faila nosaukumu un lejupielāde failu, ja tāds neeksistē.
        Ievade: URL
        Izvade: Faila saturs
    """
    # Faila nosaukumu no grāmatas url konstruēt
    filename = url_to_filename( url )
    print( "url: ", url )
    print( "filename: ", filename )

    # Ja fails vēl nav nolādēts tad lejupielādēt
    if not os.path.isfile( filename ):
        print( "downloading..." )
        urllib.request.urlretrieve( url, filename )

    # Atvērt failu ar utf-8 encoding un izvadīt faila saturu
    # TODO
        
    return text

def replace_non_ascii_by_space( text ):
    """
        Funkcija aizstāj visas Ne ASCII simbolus ar atstarpi
        Ievade: teksts
        izvade: Pārveidots teksts
    """
    return ''.join([i if ord(i) < 128 else ' ' for i in text])

#####################
## Globāli parametri
#####################

# Saraksts ar iespējamām grāmatām
gramatas = [ "https://gutenberg.org/files/834/834-0.txt", 
        "https://gutenberg.org/files/66351/66351-0.txt", 
        "https://gutenberg.org/files/108/108-0.txt" ]


# Atdalāmie simboli, kas atdala vārdus
strip = string.whitespace + string.punctuation + string.digits + "\"'" + " "


#####################
## Šeit sākas maģija
#####################

## Izmantojot fukciju  get_text  dabūt saturu no grāmatas kas atrodama files sarakstā otrā rindā
text = '' # TODO

## tekstu pārveidot tā, lai visi burti būtu ar mazo burtu (lower capital)
text = '' # TODO

## izsaukt funkciju replace_non_ascii_by_space un padot tai parametru text
text = text


# Tukša vārdnica, kur tiks saglabāts katrs vārd ar tā biežumu
words = {}

# Tekstu pa vārdiem sadalīt un saglabāt izveidotajā vārdnīcā
for word in text.split():

    # no vārda atdalīt simbolu
    word = word.strip( strip ) 
    
    # saglabāt tikai vārdus, kuri garāki par 2 simboliem
    if len( word ) > 2:
        # palielināt varda skaitu vārdnīcā par 1
        words[ word ] = 0 # TODO

## Atkomentēt assert testu, lai pārbaudītu rezultātu
# assert words==helperMajasdarbs.solution_1 # TODO
        
## Izveidot listi ar 100 biežāk lietotiem vārdiem
top_vardi = []

# TODO parametrs top_vardi ir liste ar 100 biežākiem vārdiem no vārdnīcas words

print(top_vardi)
## Atkomentēt assert testu, lai pārbaudītu rezultātu
# assert top_vardi==helperMajasdarbs.solution_1_top # TODO


##  Izveido vārdnīcu "words", kas satur visu 3 grāmatu vārdus 
# (līdzīgi kā ar vienu grāmatu augšā, bet jāiterē cauri grāmatām)

# TODO

## Kādi top 100 no visām 3 grāmatām?

# TODO 

## Atkomentēt assert testu, lai pārbaudītu rezultātu
#assert top_vardi==helperMajasdarbs.solution_all_top
