local blueprints = {

}

local scenes = {
    Test = {
        suelo = {
            handler = "suelo",
                components = {
                    Transform = {
                        position = {0, -10, -15},
                    },
                     Collider = {
                        scale = {15, 1, 30},
                        shapeType = "Cube"
                    }
                }
        },
        pared1 = {
            handler = "pared1",
                components = {
                    Transform = {
                        position = {-20, 0, -15},
                    },
                     Collider = {
                        scale = {5, 10 , 30},
                        shapeType = "Cube"
                    },
                    TestComponent = 0
                    
                }
        },
        pared2 = {
            handler = "pared2",
                components = {
                    Transform = {
                        position = {20, 0, -15},
                    },
                     Collider = {
                        scale = {5, 10 , 30},
                        shapeType = "Cube"
                    }
                }
        },
        pared3 = {
            handler = "pared3",
                components = {
                    Transform = {
                        position = {0, 0, -30},
                    },
                     Collider = {
                        scale = {15, 10, 5},
                        shapeType = "Cube"
                    }
                }
        },
        cam = {
            handler = "cam",
            components = {
                Transform = {
                    position = {0, 50, 140},
                    rotation = {1,0,0,-0.3}
                },
                Camera = {
                    nearClipDistance = 1,
                    autoAspectRatio = true,
                    backgroundColor = {0.6, 0.3, 0.3}
                },
                AudioListener = 0
            }
        },
        luz = {
            components = {
                Transform = {
                    position = {20, 80, 0}
                },
                Light = {
                    type = 0 
                }
            }
        }
    }
}

return blueprints, scenes