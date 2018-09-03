# pocketAP

A tiny WiFi access point for on-the-go connections.

## Firmware

TODO: more details on firmware

## Hardware

pocketAP is based on the Espressif ESP8266 WiFi SoC. The current hardware implementation used the original ESP-01 module, but this firmware should work largely unchanged on any ESP8266 dev board, such as the [Adafruit HUZZAH ESP8266 Breakout](https://www.adafruit.com/product/2471) or [Feather HUZZAH](https://www.adafruit.com/product/3404).

TODO: more details on hardware

## pocketAP Development

pocketAP was developed on [Platform IO](http://platformio.org). To build the firmware, clone this repo and run

```sh
pio run
```

Alternatively, you can use one of the Platform IO editor or IDE intergrations. I personally use Visual Studio Code.

## Why did I build pocketAP?

I have had occasions where I have needed a small, local network for a couple of devices. For example, when working on iOS development at a remote site, it helps if I can run everything on a little network so that Xcode can see my phone for remote builds.

While I could have used something off-the-shelf, I decided that I needed something that was:

* Battery-powered - with optional power from a standard USB port
* Cheap - or at least, cheap-ish
* Small - ideally, I can drop it in my pocket
* Hackable - so that I can change the firmware to update my needs
* Customizable - see "Hackable", but for hardware

The design I came up with is simple, uses off-the-shelf prototyping components that I mostly already had around my workspace, and can be housed in a 3D-printed case. It is based around a cheap, popular WiFi SoC and can exist on varying hardware. It uses the Arduino framework and ESP8266 Core for Arduino, so the firmware is pretty simple and accessible to anyone who wants to hack on it.

I was able to pull together most of the hardware and firmware is a few hours of effort, which is ideal, because I have other stuff I need to work on. And I can always come back to extend the feature set of pocketAP as needed. The hardware is pretty generic, too, so I can use it as the basis for other WiFi-connected things, too.

## License

pocketAP is copyright (c) 2018 George White <stonehippo@gmail.com>.

This code is licensed under GPL v3. License is available [here](/LICENSE).