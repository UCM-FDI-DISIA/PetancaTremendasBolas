local blueprints = {
	ball = {
        handler = "ball",
            components = {
                Transform = {
                    position = {0, 50, 0},
                    scale = {5, 5, 5}
                },
                RigidBody = {
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
                },
                Mesh={
                    mesh ="Bola.mesh",
                    material= "MatPePa"
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
	Floor= {
		components = {
			Transform= {
				position = {0,0,0},
				rotation = {0,0,0,1},
				scale = {1,1,1}
			}
		},
		children = {
			
			Cube= {
				components = {
					Transform= {
						position = {33,0.3,23.9},
						rotation = {0,0,0,1},
						scale = {70,0.2,100}
					},
					RigidBody= {
						static = true,
						friction = 0.1						
					}
				}
			},
			
			Sphere= {
				components = {
					Transform= {
						position = {32.2,-0.5,-26.8},
						rotation = {0,-0.0008726012,0,0.9999996},
						scale = {102,0.2,70}
					},
					RigidBody= {
						static = true,
						friction = 0.1						
					}
				}
			},
			
			Cube_1= {
				components = {
					Transform= {
						position = {24,0,17.3},
						rotation = {0.0001216634,0.07842507,0.004945832,0.9969078},
						scale = {70,0.2,100}
					},
					RigidBody= {
						static = true,
						friction = 0.1						
					}
				}
			},
			
			Cube_2= {
				components = {
					Transform= {
						position = {40.5,-0.8,18.3},
						rotation = {-0.0006571026,-0.07842201,0.004902827,0.996908},
						scale = {70,0.2,100}
					},
					RigidBody= {
						static = true,
						friction = 0.1						
					}
				}
			}
		}
	},

	Estatua= {
		components = {
			Transform= {
				position = {32.6,17.4,-35.4},
				rotation = {0,0,0,1},
				scale = {5,5,5}
			},
			Mesh = {
				mesh = "estatua.mesh"
			}
		}
	},

	Hielo= {
		components = {
			Transform= {
				position = {33,0.5,-35.7},
				rotation = {3.1415/2,0,0,1},
				scale = {0.9,0.2,0.2}
			},
			Collider = 0,
			Mesh = {
				mesh = "Crate.mesh"
			}
		}
	},

	PortonLateral= {
		components = {
			Transform= {
				position = {-43.90685,-87.37549,19.09224},
				rotation = {0,0,0,1},
				scale = {3,5,5}
			},
			Collider=0,
			Mesh = {
				mesh = "porton.mesh"
			}
		}
	},

	PortonCentral= {
		components = {
			Transform= {
				position = {-10.77684,-87.37549,19.09224},
				rotation = {0,0,0,1},
				scale = {5,5,5}
			},
			Collider=0,
			Mesh = {
				mesh = "porton.mesh"
			}
		}
	},

	Column= {
		components = {
			Transform= {
				position = {-72.04169,-35.78901,37.71354},
				rotation = {0,0,0,1},
				scale = {20,20,20}
			},
			Collider = {
				shapeType = "Cylinder"				
			},
			Mesh = {
				mesh = "column.mesh"
			}
		}
	},

	BigColumn= {
		components = {
			Transform= {
				position = {-89.1,-48.7446,-15.3},
				rotation = {0,0,0,1},
				scale = {30,23.679,30}
			},
			Collider = {
				shapeType = "Cylinder"				
			},
			Mesh = {
				mesh = "column.mesh"
			}
		}
	},

	EdificioGrande= {
		components = {
			Transform= {
				position = {94.8,9.1,47.6},
				rotation = {0,0.6755902,0,0.7372774},
				scale = {4,4,4}
			},
			Collider=0,
			Mesh = {
				mesh = "Building.mesh"
			}
		}
	},

	EdificioMediano= {
		components = {
			Transform= {
				position = {96.2,7.4,-6.22},
				rotation = {0,0.6755902,0,0.7372774},
				scale = {3,3,3}
			},
			Collider=0,
			Mesh = {
				mesh = "Building.mesh"
			}
		}
	},

	Fuente= {
		components = {
			Transform= {
				position = {32.7,1.18,-5},
				rotation = {0,0,0,1},
				scale = {10,10,10}
			},
			Collider = {
				shapeType = "Cylinder"				
			},
			Mesh = {
				mesh = "Fountain.mesh"
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
                        position = {0, -10, 0},
                        scale = {200,10,200}
                    },
                    RigidBody= {
                        friction=1,
                        static = true
                    },
                    Mesh={
                        mesh ="sphere.mesh",
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
                    position = {35, 15, 120}
                },
                Camera = {
                    nearClipDistance = 1,
                    autoAspectRatio = true,
                    backgroundColor = {0.4, 0.6, 0.9}
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
		},
		Floor1= {
			blueprint = "Floor",
			components = {
				Transform= {
					position = {0,0,0},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				}
			}
		},

		Estatua1= {
			blueprint = "Estatua",
			components = {
				Transform= {
					position = {32.6,17.4,-35.4},
					rotation = {1,0,0,1},
					scale = {5,5,5}
				}
			}
		},

		Hielo1= {
			blueprint = "Hielo",
			components = {
				Transform= {
					position = {33,0.5,-35.7},
					rotation = {0,0,0,1},
					scale = {0.9,0.2,0.2}
				}
			}
		},

		PortonesReales= {
			components = {
				Transform= {
					position = {43.90685,87.87549,13.37777},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				}
			},
			children = {
				
				PortonLateral2= {
					blueprint = "PortonLateral",
					components = {
						Transform= {
							position = {-43.90685,-87.37549,19.09224},
							rotation = {0,0,0,1},
							scale = {3,5,5}
						}
					}
				},
				
				PortonCentral1= {
					blueprint = "PortonCentral",
					components = {
						Transform= {
							position = {-10.77684,-87.37549,19.09224},
							rotation = {0,0,0,1},
							scale = {5,5,5}
						}
					}
				},
				
				PortonLateral3= {
					blueprint = "PortonLateral",
					components = {
						Transform= {
							position = {22.09315,-87.37549,19.09224},
							rotation = {0,0,0,1},
							scale = {3,5,5}
						}
					}
				}
			}
		},

		ColumnasReales= {
			components = {
				Transform= {
					position = {75.44169,34.68901,-23.91354},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				}
			},
			children = {
				
				Column4= {
					blueprint = "Column",
					components = {
						Transform= {
							position = {-72.04169,-35.78901,37.71354},
							rotation = {0,0,0,1},
							scale = {20,20,20}
						}
					}
				},
				
				Column5= {
					blueprint = "Column",
					components = {
						Transform= {
							position = {-8.541687,-35.78901,37.71354},
							rotation = {0,0,0,1},
							scale = {20,20,20}
						}
					}
				},
				
				Column6= {
					blueprint = "Column",
					components = {
						Transform= {
							position = {-76.34169,-35.78901,1.913536},
							rotation = {0,0,0,1},
							scale = {20,20,20}
						}
					}
				},
				
				Column7= {
					blueprint = "Column",
					components = {
						Transform= {
							position = {-2.141685,-35.78901,0.2135353},
							rotation = {0,0,0,1},
							scale = {20,20,20}
						}
					}
				},
				
				BigColumn8= {
					blueprint = "BigColumn",
					components = {
						Transform= {
							position = {-89.1,-48.7446,-15.3},
							rotation = {0,0,0,1},
							scale = {30,23.679,30}
						}
					}
				},
				
				BigColumn9= {
					blueprint = "BigColumn",
					components = {
						Transform= {
							position = {-77.1,-48.7446,-26.5},
							rotation = {0,0,0,1},
							scale = {30,23.679,30}
						}
					}
				},
				
				BigColumn10= {
					blueprint = "BigColumn",
					components = {
						Transform= {
							position = {-62.2,-48.7446,-34},
							rotation = {0,0,0,1},
							scale = {30,23.679,30}
						}
					}
				},
				
				BigColumn11= {
					blueprint = "BigColumn",
					components = {
						Transform= {
							position = {-46.8,-48.7446,-39.60001},
							rotation = {0,0,0,1},
							scale = {30,23.679,30}
						}
					}
				},
				
				BigColumn12= {
					blueprint = "BigColumn",
					components = {
						Transform= {
							position = {-30.10001,-48.7446,-39.60001},
							rotation = {0,0,0,1},
							scale = {30,23.679,30}
						}
					}
				},
				
				BigColumn13= {
					blueprint = "BigColumn",
					components = {
						Transform= {
							position = {-14.2,-48.7446,-37},
							rotation = {0,0,0,1},
							scale = {30,23.679,30}
						}
					}
				},
				
				BigColumn14= {
					blueprint = "BigColumn",
					components = {
						Transform= {
							position = {0.9,-48.7446,-29.7},
							rotation = {0,0,0,1},
							scale = {30,23.679,30}
						}
					}
				},
				
				BigColumn15= {
					blueprint = "BigColumn",
					components = {
						Transform= {
							position = {12.2,-48.7446,-18.8},
							rotation = {0,0,0,1},
							scale = {30,23.679,30}
						}
					}
				}
			}
		},

		izq= {
			components = {
				Transform= {
					position = {0,0,0},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				}
			},
			children = {
				
				EdificioGrande2= {
					blueprint = "EdificioGrande",
					components = {
						Transform= {
							position = {94.8,9.1,47.6},
							rotation = {0,0.6755902,0,0.7372774},
							scale = {4,4,4}
						}
					}
				},
				
				EdificioMediano2= {
					blueprint = "EdificioMediano",
					components = {
						Transform= {
							position = {96.2,7.4,-6.22},
							rotation = {0,0.6755902,0,0.7372774},
							scale = {3,3,3}
						}
					}
				}
			}
		},

		dr= {
			components = {
				Transform= {
					position = {-20.20126,13.78036,47.12299},
					rotation = {0,0,0,1},
					scale = {1,1,1}
				}
			},
			children = {
				
				EdificioGrande3= {
					blueprint = "EdificioGrande",
					components = {
						Transform= {
							position = {9.401261,-4.880364,0.4770088},
							rotation = {0,0.7489557,0,0.6626201},
							scale = {4,4,4}
						}
					}
				},
				
				EdificioMediano3= {
					blueprint = "EdificioMediano",
					components = {
						Transform= {
							position = {1.9,-7.28,-53.32},
							rotation = {0,0.7489557,0,0.6626201},
							scale = {3,3,3}
						}
					}
				}
			}
		},

		Fuente1= {
			blueprint = "Fuente",
			components = {
				Transform= {
					position = {32.7,1.18,-5},
					rotation = {1,0,0,1},
					scale = {10,10,10}
				}
			}
		}
	}	
}
return blueprints, scenes