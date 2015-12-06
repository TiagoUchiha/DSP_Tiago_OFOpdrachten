# Eindopdracht Openframeworks V3 #

**Be One With Music (aka. B1WM)**

**Tiago Dos Santos Pedrosa - IAD 2**

**06/12/15 - Edwin van Ouwerkerk**



## Concept: ##
Voor grafische vormgeving project wordt er aan de student gevraagd om een interactieve poster te maken.
Hierbij heb ik de eindopdracht van openframeworks samen gedracht met de grafische vormgeving opdracht.

Be One With Music, ofterwijl B1WM is een poster die op verschillende vaste locatie in Amsterdam (voorlopig) wordt neergezet. De poster bestaat uit 1 beeldscherm, 5 Witte lEDS, 1 RGB LED en 1 muziek noot speaker.

B1WM is een project om mensen samen te brengen. Je kunt de samenverband verdelen onder verschillende kringen zoals wijken of steden. De gebruiker kiest zijn eigen wijk/stad, maakt een selfie/foto van de plaats dat hij/zij zich bevindt en aansluit op zijn eerste keus en kiest ook een liedje die voor hem/haar past bij die bepaalde plaats/foto.

Voorbeeld:
Een man woont in Amsterdam West. Hij houdt heel veel van zijn wijk en vindt voornamelijk een bepaalde parkje dichtbij zijn huis heel erg rust gevend. Hij maakt een foto van die park en kiest een liedje die voor hem past bij die plaats. Via zijn smartphone kan hij op de website van B1WM kiezen op welke stad en wijk hij zich bevindt. Dan kan hij de afbeelding en de geluid uploaden.

De poster:
Op de poster bevindt zich een speaker ernaast en een aanwijzing waar de gebruiker de speaker moet plaatsen op de poster. Als de gebruiker op de juiste plaats neerzet, geeft de RBG LED een feedback terug (het gaat groen branden). Er wordt dan een afbeelding tentoongesteld op het beeldscherm en de bijhorende geluid wordt afgespeeld vanuit de speaker. Er gaat dan een witte lampje branden onderin met een uitleg dat de gebruiker met zijn smartphone het geluid kan downloaden door de NFC-reader functie te gebruiken van zijn smartphone. Er staan dan 5 verschillende NFC stickers die hij kan scannen.
Boven die NFC stickers staan de witte lampjes, die aangeeft welke sticker bij welke geluid hoort die afgespeeld wordt.


## Werking: ##

De code is een software voor grafische vormgeving project.

In deze code wordt er een poster afgebeeld op het beeldscherm. Als de gebruiker de speaker (of iets dergelijks) voor de lichtsensor
neerzet, dan wordt er gekeken hoe goed het object gepositioneerd is op de lichtsensor, de RGB LED geeft als feedback aan of je dat goed hebt gedaan.
Rood = slecht, Blauw = bijna goed en groen = goed. Als het goed is (onder de 120), dan wordt het eerste geluid afgespeeld en de bijhorende plaatje wordt getoont op het beeldscherm.Verder gaat de bijhorende witte LED branden, dus geluid 1 heeft witte Led 1. De witte LEDS laten zien waar de gebruiker met zijn smartphone NFC reader het geluid kan downloaden die hij/zij te horen krijgt. De NFC functionaliteit wordt in deze code niet geprogrammeerd. Het valt buiten de openframeworks opdracht.


## Pseudo code: ##

Speaker:

If lightsensorValue < 120

	RGB LED = green
	speaker is in the right place
	start playing soundarray
	start drawing images

else if lightsensorValue > 120 or < 400

	RGB LED = blue
	speaker is on top of the right place,
	but not insert correctly
	turn sound and images off

else

	RGB LED = red
	speaker inst in the right place
	turn sound and images off

-----------------------------------------------------------------------------

Sound

If no sound is playing

	turn sound[0] on
	draw image[0]
	set white Led 1 on

else if sound[0] is finished

	turn sound[1] on
	draw image[1]
	set white Led 2 on

else if sound[1] is finished

	turn sound[2] on
	draw image[2]
	set white Led 3 on

else if sound[2] is finished

	turn sound[3] on
	draw image[3]
	set white Led 4 on

else if sound[3] is finished

	turn sound[4] on
	draw image[4]
	set white Led 5 on




## Benodigdheden: ##

 Actuator:
 
- 5 White LEDS
- 1 RGB LED

Sensoren:

- Light sensor


Objecten:

- Muziek noot speaker

- Beeldscherm

- NFC stickers


