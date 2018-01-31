# ADS1115 ADC
Analog to Digital Converter (with Programmable Gain Amplifier)

# See video #104 at https://www/youtube.com/RalphBacon
(Direct link to video: https://youtu.be/8qGr6Q5Ymps)

The analog accuracy and sensitivity of the standard Uno / Nano pins is about 5mv per 'step' that we can read from executing
an AnalogRead. Fine for many purposes but not so great if you're trying to measure at sub-millivolt levels. And if you have an
ESP8266 with just one input, or a Raspberry Pi with no analog pins at all this could be the answer you're looking for.

Enter the ADS1115 analog-to-digital converter with a maximum resolution of 0.184mV per 'step', although as this device has a
Programmable Gain Amplifier (PGA) on board it's easy to change that.

Nothing is perfect, though, so watch the video for some gotchas and coding techniques we can use to maximize the usefulness
of this device.

Sketch used in the demo (including the averaging function) is in the Github.  
https://github.com/RalphBacon/ADS1115-ADC

Where I bought my ADS1115 ADC  
https://www.aliexpress.com/item/ADS1115-ADC-ultra-compact-16-precision-ADC-module-development-board/32313388618.html

Adafruit do a library and everything! Not used in this demo but doubtless worth a look.  
https://www.adafruit.com/product/1085  
https://learn.adafruit.com/adafruit-4-channel-adc-breakouts?view=all

Datasheet is in the GitHub, worth reading the bit about registers.  
https://github.com/RalphBacon/ADS1115-ADC

---

If you like this video please give it a thumbs up, share it and if you're not already subscribed please consider doing so :)

My channel is here:
------------------------------------------------------------------
https://www.youtube.com/c/RalphBacon
------------------------------------------------------------------ 
How can I remember this? Memory tip: "See" Ralph Bacon, geddit?
[You can also use this link: https://www.youtube.com/RalphBacon]
