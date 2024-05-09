local prefabs = {
    ball = {
        handler = "ball",
            components = {
                Transform = {
                    position = {0, 50, 0}
                },
                RigidBody = {
                    scale = {5, 5, 5},
                    mass = 0.01,
                    gravity = {0,-9.8,0},
                    friction = 1,
                    restitution = 0,
                    shapeType = "Sphere",
                    static = false,
                    layer = "ALL", 
                    trigger = false
                },
                ShootComponent = {
                    maxForce=500
                }
            }
    },
    
    boliche = {
        handler = "boliche",
        components = {
            Transform = {
                position = {0, 50, 0}
            },
            RigidBody = {
                scale = {2, 2, 2},
                mass = 0.005,
                gravity = {0,-9.8,0},
                friction = 0.5,
                restitution = 0,
                shapeType = "Sphere",
                static = false,
                layer = "ALL", 
                trigger = false
            },
            ShootComponent = {
                maxForce=100
            }
        }
    },
    Paellera = {
		components = {
			Transform = {
				position = {0,-0.9,-11.4},
				scale = {1,1,1}
			},
			Mesh = {
				mesh = "paellera.mesh"			
			}
		}
	},
    Stairs = {
		components = {
			Transform = {
				position = {-2.2,0,-2.8},
				rotation = {0,0.1736482,0,0.9848078},
				scale = {1,1,1}
			}
		},
		children = {
			Cube = {
				components = {
					Transform = {
						position = {0,0,0},
						rotation = {0,0,0,1},
						scale = {2,0.3,1}
					},
					Collider = {					
					}
				}
			},
			Cube_1 = {
				components = {
					Transform = {
						position = {0,-0.3,-0.5},
						rotation = {0,0,0,1},
						scale = {2,0.3,2}
					},
					Collider= {					
					}
				}
			},
			Cube_2 = {
				components = {
					Transform = {
						position = {0,-0.6,-1},
						rotation = {0,0,0,1},
						scale = {2,0.3,3}
					},
					Collider = {				
					}
				}
			},
			Cube_3 = {
				components = {
					Transform = {
						position = {0,-0.9,-1.5},
						rotation = {0,0,0,1},
						scale = {2,0.3,4}
					},
					Collider = {					
					}
				}
			},
			Cube_4 = {
				components = {
					Transform = {
						position = {0,-1.2,-2},
						rotation = {0,0,0,1},
						scale = {2,0.3,5}
					},
					Collider = {					
					}
				}
			}
		}
	}
}

local scenes = {
    Test = {
        GameManager = {
            handler = "GameManager",
                components = {
                    GameManager = 0
                }
        },
        suelo = {
            handler = "Suelo",
            components = {
                Transform = {
                    position = {0, -10, 0}
                },
                RigidBody= {
                    scale = {500,10,500},
                    static = true
				},
                Collider = {
                    scale = {1000, 5, 1000}
                }
            }
		},
        player = {
           	handler = "Player",
            components = {
                Transform = {
                    position = {0, 50, 0}
                }
            }
        },
        cam = {
            handler = "cam",
            components = {
                Transform = {
                    position = {0, 50, 250}
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
	},

	SkinSelection = {
        previewBall = {
            handler = "PreviewBall",
            components = {
                Transform = {
                    position = {0, 0, 0}
                },
                Mesh = {
                    mesh = "Bola.mesh"
                },
                RotateComponent = {
					rotationSpeed = 60
				}
            }
        },
        selectionManager = {
            handler = "SelectionManager",
            components = {
                Transform = {
                    position = {0, 0, 0}
                },
                SelectionManager = {
                    materials = {
						"MatPePa",
						"MatRojo",
                        "MatCarlos",
                        "MatRome",
                        "MatBolaDragon",
                        "MatTenis"
					}
                }
            }
        },
        cam = {
			components = {
				Transform = {
					position = {0, 0, 0}
				},
				Camera = {
					nearClipDistance = 1,
					autoAspectRatio = true,
					backgroundColor = {0.6, 0.3, 0.3}
				},
				AudioListener = 0
			}
		},
		leftArrow = {
            handler = "Arrow",
			components = {
				RectTransform = {
					position = {100, 200},
                    scale = {100, 100}
				},
                Button = {
                    out = "panko.png",
                    clicked = "panko.png",
                    hover = "panko.png",
					onClick = function (inv)
                        print("holi");
	                    inv:invoke("moveLeft");
                        print("holi2");
                    end 
				}
			}
		},
        rightArrow = {
            handler = "rArrow",
			components = {
				RectTransform = {
					position = {450, 200},
                    scale = {100, 100}
				},
                Button = {
                    out = "panko.png",
                    clicked = "panko.png",
                    hover = "panko.png",
					onClick = function (inv)
                        print("holi");
	                    inv:invoke("moveRight");
                        print("holi2");
                    end 
				}
			}
		},
        selectButton = {
            handler = "selectButton",
			components = {
				RectTransform = {
					position = {275, 350},
                    scale = {100, 100}
				},
                Button = {
                    out = "panko.png",
                    clicked = "panko.png",
                    hover = "panko.png",
					onClick = function (inv)
                        print("holi");
	                    inv:invoke("selectSkin");
                        print("holi2");
                    end 
				}
			}
		}
	},

	TitleScreen = {
		cam = {
			components = {
				Transform = {
					position = {0, 0, 10}
				},
				Camera = {
					nearClipDistance = 1,
					autoAspectRatio = true,
					backgroundColor = {0.6, 0.3, 0.3}
				},
				AudioListener = 0
			}
		},
		logo = {
			components = {
				RectTransform = {
                    position = {0, 0},
                    scale = {600, 200}
                },
                Image = {
					depth = 0,
					texture = "petancaLogo.png"
				}
			}
		},
        playButton = { 
            components = {
                RectTransform = {
                    position = {180,200},
                    scale = {150,30}
                },
                Button = {
                    depth = 2,
                    out = "playOnOut.png",
                    hover = "playOnOver.png",
                    clicked = "playOnClick.png"
                }
            }
        },
    },

	Valencia = {
        cam = {
            components = {
                Transform = {
                    position = {0, 0, 0},
                    rotation = {0, 0, 0, 1}
                },
                Camera = {
                    nearClipDistance = 1,
                    autoAspectRatio = true,
                    backgroundColor = {0.6, 0.3, 0.3}
                },
                AudioListener = 0
            }
        },
        Plataformainicial = {
            components = {
                Transform = {
                    position = {0,-0.6,0},
                    scale = {8,1.5,4}
                },
                Collider = {
                    scale = {1,1,1}		
                },
                --Mesh = {
                --    mesh = "cube.mesh"
                --}
            }
        },
		Map1 = {
			components = {
				Transform = {
					position = {0,-0.6,-2.3},
					scale = {5.95,1.5,0.75}
				},
				Collider = {

				}
			}
		},
		Map2 = {
			components = {
				Transform = {
					position = {0,-1.5,-7.5},
					scale = {9,0.3,11}
				},
				Collider = {				
				}
			}
		},
		Map3 = {
			components = {
				Transform= {
					position = {5.9,-1.5,-10.3},
					scale = {17,0.3,1}
				},
				Collider = {					
				}
			}
		},
		Map4 = {
			components = {
				Transform= {
					position = {-5.9,-1.5,-10.3},
					scale = {17,0.3,1}
				},
				Collider = { 					
				}
			}
		},
		Map5 = {
			components = {
				Transform= {
					position = {-4.7,-1.5,-9.7},
					scale = {1.25,0.3,9}
				},
				Collider = {				
				}
			}
		},
		Map6 = {
			components = {
				Transform= {
					position = {4.7,-1.5,-9.7},
					scale = {1.25,0.3,9}
				},
				Collider = {			
				}
			}
		},
		Map7 = {
			components = {
				Transform= {
					position = {-4.46,-0.6,-1.91},
					scale = {0.02,1.5,0.95}
				},
				Collider = {			
				}
			}
		},
		Map8 = {
			components = {
				Transform= {
					position = {4.46,-0.6,-1.91},
					scale = {0.02,1.5,0.95}
				},
				Collider = {			
				}
			}
		},
        Cylinder = {
			components = {
				Transform = {
					position = {0,-1.5,-18.6},
					rotation = {0,0,0,1},
					scale = {15.7,0.15,15.7}
				},
				Collider = {
					shapeType = "Cylinder"					
				}
			}
		},
        Paellera1 = {
			blueprint = "Paellera",
			components = {
				Transform = {
					position = {0,-0.9,-11.4},
					rotation = {-0.2164395,0,0,0.9762961},
					scale = {1,1,1}
				}
			}
		},
		Paellera2 = {
			blueprint = "Paellera",
			components = {
				Transform = {
					position = {4,-1.2,-15},
					rotation = {0,-0.3007057,0,0.953717},
					scale = {1,1,1}
				}
			}
		},
		Paellera3 = {
			blueprint = "Paellera",
			components = {
				Transform = {
					position = {-4,-1.2,-15},
					rotation = {0,0.5372996,0,0.8433915},
					scale = {1,1,1}
				}
			}
		},
        Stairs1 = {
			blueprint = "Stairs",
			components = {
				Transform= {
					position = {-2.2,0,-2.8},
					rotation = {0,0.1736482,0,0.9848078},
					scale = {1,1,1}
				}
			},
			children = {
				Cube = {
					components = {
						Transform = {
							position = {0,0,0},
							scale = {2,0.3,1}
						},
						Collider = {						
						}
					}
				},
				Cube_1= {
					components = {
						Transform= {
							position = {0,-0.3,-0.5},
							scale = {2,0.3,2}
						},
						Collider = {						
						}
					}
				},
				Cube_2 = {
					components = {
						Transform = {
							position = {0,-0.6,-1},
							scale = {2,0.3,3}
						},
						Collider = {		
						}
					}
				},
				Cube_3= {
					components = {
						Transform= {
							position = {0,-0.9,-1.5},
							scale = {2,0.3,4}
						},
						Collider = {		
						}
					}
				},
				Cube_4= {
					components = {
						Transform = {
							position = {0,-1.2,-2},
							scale = {2,0.3,5}
						},
						Collider = {					
						}
					}
				}
			}
		},
        Stairs2 = {
			blueprint = "Stairs",
			components = {
				Transform= {
					position = {2.2,0,-2.8},
					rotation = {0,-0.1736483,0,0.9848078},
					scale = {1,1,1}
				}
			},
			children = {
				children = {
					Cube = {
						components = {
							Transform = {
								position = {0,0,0},
								scale = {2,0.3,1}
							},
							Collider = {						
							}
						}
					},
					Cube_1 = {
						components = {
							Transform= {
								position = {0,-0.3,-0.5},
								scale = {2,0.3,2}
							},
							Collider = {						
							}
						}
					},
					Cube_2 = {
						components = {
							Transform = {
								position = {0,-0.6,-1},
								scale = {2,0.3,3}
							},
							Collider = {		
							}
						}
					},
					Cube_3 = {
						components = {
							Transform= {
								position = {0,-0.9,-1.5},
								scale = {2,0.3,4}
							},
							Collider = {		
							}
						}
					},
					Cube_4 = {
						components = {
							Transform = {
								position = {0,-1.2,-2},
								scale = {2,0.3,5}
							},
							Collider = {					
							}
						}
					}
				}
			}
		}
    }
}

return prefabs, scenes