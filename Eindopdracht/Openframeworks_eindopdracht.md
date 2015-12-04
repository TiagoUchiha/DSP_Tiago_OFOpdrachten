# Eindopdracht Openframeworks: #

**Chefrany Laitenu & Tiago Dos Santos Pedrosa**

Voor de eindopdracht van Openframeworks willen wij de interactie van onze eindopdracht voor Ontwerpen met Geluid tot leven wekken.

## Concept: ##
Ons concept gaat over dat wij een belangrijk fragment uit de geschiedenis van een object willen tonen aan een bezoeker in de vorm van een auditief verhaal.


## Werking: ##

Makey Makey 
Object : Knuffel  → Bij aanraking wordt er een geluidsfragment afgespeeld  
Object : Koffie mok → Bij aanraking wordt er een geluidsfragment afgespeeld
NeoPixels:  Geven een bepaalde kleur sequentie  bij aanraking van een van de objecten

Afstandsensor Ultrasonic ranging module : HC-SR04
De afstand die de persoon heeft tot het object bepaalt de kleur van de neopixels die rondom het object zijn geplaatst. Dus hoe dichterbij de persoon komt tot het object hoe intenser de kleurstelling wordt van de neopixels 

NeoPixels:  distance →  rgb color 


## Pseudo code: ##

Make makey/aanraken:

If touch a object
	check which sound was played
	play the next the sound in the array/ (or random)
	save the number of the sound
else
	nothing

## Neopixels/afstand: ##

If there is no one around

	then light up the pixels
	save spot from guest

else if someone is half way

	then dim the pixels
	save spot from guest

else if someone is close

	then dim the pixels more
	save spot from guest

Check if guest is there or not with spot from guest

	if someone is close and object is touched
		light up the pixels
	else don’t.


## Benodigdheden: ##

 Actuator: 

- Neopixels 

- Speakes

Sensoren:

- MakeyMakey --> aanrakingssensoren

- Afstandsensoren

Objecten:

- Knuffel

- Koffie mok

- Extra objecten voor de presentatie


