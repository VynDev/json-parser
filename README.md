Load or save your data in the JSON format.

## Quick example

```cpp
/* Load a json object from a file */
JSON::Object json("examples/basics.json");

/* Check if there is any error */
if (json.IsValid())
    cout << json.ToString() << endl;
else {
    cout << "json is not valid: " << json.GetError() << endl;
    return 1;
}

/* Modify a variable */
json["number"].AsNumber() = json["number"].AsNumber() + 1;
    
/* Save a json object */
json.Save("examples/basics_modified.json");
```

## Intallation

[TODO]

## Documentation

[TODO]