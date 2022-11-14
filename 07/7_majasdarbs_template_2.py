'''
Python 7 mājasdarbs Nr.2

Uzdevums: aizpildīt vietas ar atzīmi TODO

'''

from IntroOpenCV import IntroOpenCV
from TopWords import TopWords

# definēt klasi, kura manto klases TopVardi un IevadsOpenCV
# TODO
class Majasdarbs(IntroOpenCV, TopWords):
    def __init__(self) -> None:
        pass



if __name__ == "__main__":
    obj = Majasdarbs()

    # Atkomentēt sekojošās rindas, lai pārbaudītu vai klases ir mantotas
    # TODO
    obj.set_picture("python.jpg")
    obj.get_blue_red()
    obj.set_dict("top_vardi.json")
    obj.get_bar_plot()
