using Images , FileIO , Printf

function make_gif(folder::String , size::Int , gens ::Int , fileName::String)
    frames = []

    count = 0

    print("[")

    for i in 0:gens
        path = joinpath(folder , @sprintf("frame%d.bin" , i))
        raw  = read(path)

        grid = reshape(raw , size , size)'

        push!(frames , colorview(Gray , Float32.(grid)))

        if(i*100 // gens > count)
            print("=")
            flush(stdout)
            count += 5
        end
    end

    print("]\n")

    save(fileName , cat(frames... , dims = 3))
end

function main()
    # Get the size of the lactice and the number of generations
    gens , size = open("INPUT.dat") do io
        init_gen = parse(Bool , readline(io))
        x = parse(Int , readline(io))
        y = -1
        if init_gen
            file_name = "save/config.dat"
            if !isfile(file_name)
                file_name = ".bckup/initial.dat"
            end
            appo = open(file_name) do fin
                return readline(fin)
            end
            y = parse(Int , split(appo)[1])
        else
            readline(io)
            y = parse(Int , readline(io))
        end

        @assert (y > 0) "Not valid size"

        return x , y
    end

    make_gif("data" , size , gens , "life.gif")
end

main()
