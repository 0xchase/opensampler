# opensampler

An open source sampler plugin.

---

### User Interface

The core of the user interface is 4 tabs, each described below.

 - **Browser view**: This view is for browsing and selecting instruments. The UI will look similar to the omnisphere preset browser. Like most samplers, the instruments may be loaded from local files. The browser will also function as a package manager, so the user can download new instruments from publically maintained repositories. 

 - **Main view**: This view functions similarly to the main view in Kontakt. The user interface can be customized per instrument/preset, and the background image can be customized by the instrument creator. Customization happens in the modular view (described below), where some nodes can be "promoted to main view" as knobs/faders/etc. 

 - **Modular View**: This view is for processing midi, combining sample libraries, creating audio effects, and more with a node-based system. Nodes may be written in C++, or dynamically within the plugin using the Julia bindings. Some nodes may be promoted to the main view as knobs, faders, grids, etc.

 - **Utilities View**: This view contains various utilities for speeding up the sampling process. These include autosampling (from a hardware synth or a plugin), exporting a preset/instrument as a standalone plugin, batch processing samples with audio effects or machine learning scripts, and more.

---

