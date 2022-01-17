# Creating a new release

Releasing and uploading to platformio is automated with a github action.
Navigate to github actions and run the [release](https://github.com/functionpointer/arduino-MLX90393/actions/workflows/release.yml) automation.
Specify the version number you wish.

The automation will generate a `library.json` from the `library.json.template`, package the result and upload it to platformio.
