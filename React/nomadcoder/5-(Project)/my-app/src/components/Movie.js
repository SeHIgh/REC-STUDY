import PropTypes from "prop-types";
import { Link } from "react-router-dom";
import styles from "../styles/movie.module.css";

function Movie({ id, coverImg, title, summary, genres }) {
  return (
    <div className={styles.cont}>
      <Link to={`/movie/${id}`}>
        <img className={styles.coverImg} src={coverImg} alt={title} />
        <h2 className={styles.title}>{title}</h2>
      </Link>
      <div className={styles.genres}>
        <h3>장르</h3>
        <ul>
          {genres.map((g) => (
            <li key={g}>{g}</li>
          ))}
        </ul>
      </div>
    </div>
  );
}

Movie.propTypes = {
  id: PropTypes.number.isRequired,
  coverImg: PropTypes.string.isRequired,
  title: PropTypes.string.isRequired,
  summary: PropTypes.string.isRequired,
  genres: PropTypes.arrayOf(PropTypes.string).isRequired,
};

export default Movie;
