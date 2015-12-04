#**Opdracht Les2**

##Wat is het verschil tussen de array- en de 'vector' varianten?
Een vector gedraagt zich zoals een array, maar een vector kan dynamisch
zijn grootte veranderen. De grootte wordt automatisch bepaald door de *container*.
http://www.cplusplus.com/reference/vector/vector/

##Hoe zou je deze installatie kunnen maken?
Voor de *No Eye Contact Allowed* heb ihttp://www.cplusplus.com/reference/vector/vector/k een water pomp met een slang nodig die de water kan spuiten.
Verder heb ik ook een kleine camera nodig die de gezichten van dehttp://www.cplusplus.com/reference/vector/vector/ mensen kan herkennen door de gaatjes van de model,
een sculptuur met 2 gaten waar de ogen zitten en een vitrine kast zo dat de toeschouwers niet nat worden.
Daarnaast is het belangrijk om een kleine pc of arduino te hebben en eletriciteit.

##Beschrijf wat je er voor nodig zou hebben (software en hardware).
Beschrijf zo precies mogelijk wat de software zou moeten doen. (Maak een stappenplan)

Om dit te laten werken heb ik een arduino/kleine pc nodig die gelinkt is aan de camera.
De camera filmt de omgeving en als die dan hoofden van mensen ziet op de scherm en er
ogen in herkent dan wordt er een signaal gestuurd naar de pomp om water te spuiten vanuit de ogen.

1. De software checkt constant wat de camera ziet
2. Als er een persoon langs loopt dan checkt de software of die ogen herkent.
(door warmtesensoren ofzo? hier zit in zelf vast hoe het herkent wordt.)
3. Als de software geen ogen herkent dan stuurt die geen signaal aan de pomp en blijft die checken op ogen.
4. Als de software wel ogen herkent dan stuurt die een signaal aan de pomp om open te gaan.
5. De pomp wordt aangezet door de software voor een bepaalde tijd, bijvoorbeeld 3 seconden.
6. De software telt tot 3 en stuurt een signaal weer dat de pomp dicht moet gaan.
7. De pomp krijgt de signaal en sluit het af.
8. De software begint opnieuw te checken of er mensen/ogen door de camera wordt herkent.